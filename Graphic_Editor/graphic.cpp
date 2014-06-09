
#include "stdafx.h"
#include "graphic.h"
#include "MainFrm.h"
#include "Graphic_editorDoc.h"
// #include "1Line.cpp"
//

	// Creator, Destroyer
	//graphic::graphic(){ };	// 생성자		// 특별한 구현 없음
	//graphic::~graphic();		// 소멸자

	// mutator
	int graphic::moveApoint(int index, CPoint dest)
	{	points[index] = dest;	return 0;			}
	int graphic::moveAll(CPoint base, CPoint dest)
	{	for(int i=0; i<pointNumber; i++)
			points[i] += (dest - base);
		return 0;									}
	int graphic::chgState(int a)		{State = a; return 0;}
	int graphic::addPoint(CPoint a)		{points[pointNumber++] = a; return 0;}
	int graphic::chgPoint(int index, CPoint a){ points[index] = a; return 0;}
	int graphic::chgLineSz(int a)		{lineSz = a; return 0;}
	int graphic::chgLineStyle(int a)	{lineStyle = a; return 0;}
	int graphic::chgColor(COLORREF a)	{colors[0] = a; return 0;}
	int graphic::chgColor2(COLORREF a)	{colors[1] = a; return 0;}
	int graphic::chgColorNumber(int a)	{colorNumber = a; return 0;}
	int graphic::chgHatch(int a)		{hatchFlag = a; return 0;}
	int graphic::initPN()				{pointNumber = 0; return 0;}
	// accessor
	int		 graphic::getState()			{return State;}
	CPoint	 graphic::getPoint(int index)	{return points[index];}
	int		 graphic::getPointNumber()		{return pointNumber;}
	int		 graphic::getLineSz()			{return lineSz;}
	int		 graphic::getLineStyle()		{return lineStyle;}
	COLORREF graphic::getColor(int index)	{return colors[index];}
	int		 graphic::getColorNumber()		{return colorNumber;}
	int		 graphic::getHatch()			{return hatchFlag;}
	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
	int graphic::selectPoint(CPoint mouse, int index)
	{	// point 를 클릭하는지 체크
		long X = points[index].x - lineSz/2;
		long Y = points[index].y - lineSz/2;
		if(mouse.x >=  X - 1 && mouse.x <= X + lineSz + 1)
		{	
			if(mouse.y >= Y - 1 && mouse.y <= Y + lineSz + 1)
			{
				return index;
			}
		}
		return -1;
	}
	int graphic::enGroup(){	return -1;}
	int graphic::deGroup(){	return -1;}
	int graphic::checkIn(CPoint mouse, graphic o[200], int c)
	{	
		for(int i=0; i<c; i++){
			switch(o[i].getState()){
			case 1 : // line
				{
					int temp = inLine(mouse, o[i].getPoint(0), o[i].getPoint(1), o[i].getLineSz());
					if (temp == 0) {
						// select
						return i;
					}
					else break;
				}
			case 2 : // polyline
				for(int k=0; k<o[i].getPointNumber()-1; k++){
					int temp = inLine(mouse, o[i].getPoint(k), o[i].getPoint(k+1), o[i].getLineSz());
					if(temp == 0){
						// select
						return i;
					}
				} break;
			case 3 : // ellipse
				{
					int temp = inEllipse(mouse, o[i].getPoint(0), o[i].getPoint(1));
					if(temp == 0){
						// select
						return i;
					}
				}
				break;
			case 4 : // rectangle
				{
					int temp = inRect(mouse, o[i].getPoint(0), o[i].getPoint(1));
					if(temp == 0){
						// select
					return i;
					}
				}
				break;
			case 5 : // text
				{
					int temp = inRect(mouse, o[i].getPoint(0), o[i].getPoint(1));
					if(temp == 0){
						// select
						return i;
					}
				}
				break;
			}
		}
		return -1;
	}
	CRect graphic::getLTRB(graphic o){	// 
		int left = 99999, right = 0, top = 99999, bot = 0;
		for(int i=0; i<o.getPointNumber(); i++){
			if( left >= o.getPoint(i).x ) left = o.getPoint(i).x;
			if( right <= o.getPoint(i).x ) right = o.getPoint(i).x;
			if( top >= o.getPoint(i).y ) top = o.getPoint(i).y;
			if( bot <= o.getPoint(i).y ) bot = o.getPoint(i).y;
		}
		return CRect(left - 2, top - 2, right + 2, bot + 2);
	}

	// Line
	int graphic::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint, int lineSz)
	{	// Line 에 속하는지 확인	// PolyLine 에서도 사용
		CPoint s = startPoint;		CPoint e = endPoint;
		if( (mouse.x <= s.x && mouse.x <= e.x) || (mouse.x >= s.x && mouse.x >= e.x) ) return -1;
		int Y;
		if( s.x != e.x ) Y = (double)(e.y-s.y)/(e.x-s.x) * ( mouse.x - s.x ) + s.y - lineSz/2; // 기울기 * ( X - s.x ) + s.y
		else Y = s.y;
		if( mouse.y >= Y - 1.5 && mouse.y <  Y + lineSz + 1.5 ){
			return 0;
		}
		return -1;
	}

	// PolyLine

	// Ellipse
	int graphic::inEllipse(CPoint mouse, CPoint startPoint, CPoint endPoint)
	{	// (x-mx)^2 / a^2 + (y-my)^2 / b^2 <= 1
		int left, right, top, bot;	int mx, my, a, b;
		if(startPoint.x <= endPoint.y){
			left = startPoint.x;
			right = endPoint.x;
		}
		else {
			left = endPoint.x;
			right = startPoint.x;
		}
		if(startPoint.y <= endPoint.y){
			top = startPoint.y;
			bot = endPoint.y;
		}
		else {
			top = endPoint.y;
			bot = startPoint.y;
		}
		mx = left + (right - left)/2;
		my = top + (bot - top)/2;
		a = (right - left)/2;
		b = (bot - top)/2;

		int x2, y2;
		x2 = mouse.x - mx;
		y2 = mouse.y - my;
		if( (double)(x2 * x2) / (a * a) + (double)(y2 * y2) / (b * b) <= 1 ){
			return 0;
		}
		return -1;
	}
	// Rectangle
	int graphic::inRect(CPoint mouse, CPoint startPoint, CPoint endPoint)
	{
		int left, right, top, bot;
		if(startPoint.x <= endPoint.x){
			left = startPoint.x;
			right = endPoint.x;
		}
		else {
			left = endPoint.x;
			right = startPoint.x;
		}
		if(startPoint.y <= endPoint.y){
			top = startPoint.y;
			bot = endPoint.y;
		}
		else {
			top = endPoint.y;
			bot = startPoint.y;
		}
		if( mouse.x >= left && mouse.x <= right ){
			if( mouse.y >= top && mouse.y <= bot){
				return 0;
			}
		}
		return -1;
	}
	// Text	

// graphic::
	// Groups
	Groups::Groups(){
		depth = objC = grpC = 0;
	}
	Groups::Groups(int i_depth){
		depth = i_depth;
		objC = grpC = 0;
	}
	int makeGrp(int c);		// c : count
	CPoint grpCheckin(CPoint mouse, Groups grp[], int c);	// c : count
	CRect getLTRB();