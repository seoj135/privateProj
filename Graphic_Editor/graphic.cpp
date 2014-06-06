
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
	int graphic::addPoint(CPoint a)		{points[++pointNumber] = a; return 0;}
	int graphic::chgLineWidth(int a)	{lineWidth = a; return 0;}
	int graphic::chgLineStyle(int a)	{lineStyle = a; return 0;}
	int graphic::chgColor(COLORREF a)	{colors[0] = a; return 0;}
	int graphic::chgColor2(COLORREF a)	{colors[1] = a; return 0;}
	int graphic::chgColorNumber(int a)	{colorNumber = a; return 0;}
	int graphic::chgHatch(int a)		{hatchFlag = a; return 0;}
	// accessor
	int		 graphic::getState()			{return State;}
	CPoint	 graphic::getPoint(int index)	{return points[index];}
	int		 graphic::getPointNumber()		{return pointNumber;}
	int		 graphic::getLineWidth()		{return lineWidth;}
	int		 graphic::getLineStyle()		{return lineStyle;}
	COLORREF graphic::getColor(int index)	{return colors[index];}
	int		 graphic::getColorNumber()		{return colorNumber;}
	int		 graphic::getHatch()			{return hatchFlag;}
	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
	int graphic::selectPoint(CPoint mouse, int index)
	{	// point 를 클릭하는지 체크
		long X = points[index].x - lineWidth/2;
		long Y = points[index].y - lineWidth/2;
		if(mouse.x >=  X - 1 && mouse.x <= X + lineWidth + 1)
		{	
			if(mouse.y >= Y - 1 && mouse.y <= Y + lineWidth + 1)
			{
				return index;
			}
		}
		return -1;
	}
	int graphic::enGroup(){	return -1;}
	int graphic::deGroup(){	return -1;}
	int graphic::checkIn(CPoint mouse, graphic o[200])
	{	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
		CGraphic_editorDoc* docu = (CGraphic_editorDoc*) pFrame->GetActiveDocument();
		for(int i=0; i<docu->grpC; i++){
			checkIn(mouse, docu->grp[i].obj);
			for(int j=0; j<docu->grp[i].GroupNum; j++){
				checkIn(mouse, docu->grp[i].grp[j].obj);
			}
		}
		for(int i=0; i<docu->objC; i++){
			switch(docu->obj[i].getState()){
			case 1 : // line
				{
					int temp = inLine(mouse, docu->obj[i].getPoint(0), docu->obj[i].getPoint(1));
					if (temp == 0) {
						// select
					}
					else break;
				}
			case 2 : // polyline
				for(int k=0; k<docu->obj[i].getPointNumber()-1; k++){
					int temp = inLine(mouse, docu->obj[i].getPoint(k), docu->obj[i].getPoint(k+1));
					if(temp == 0){
						// select
					}
				} break;
			case 3 : // ellipse
				break;
			case 4 : // rectangle
				break;
			case 5 : // text
				break;
			}
		}
		return 0;
	}

	// Line
	int graphic::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint)
	{	// Line 에 속하는지 확인	// PolyLine 에서도 사용
		CPoint s = startPoint;		CPoint e = endPoint;
		if( (mouse.x <= s.x && mouse.x <= e.x) || (mouse.x >= s.x && mouse.x >= e.x) ) return -1;
		int Y;
		if( s.x != e.x ) Y = (e.y-s.y)/(e.x-s.x) * ( mouse.x - s.x ) + s.y - lineWidth/2; // 기울기 * ( X - s.x ) + s.y
		else Y = s.y;
		if( mouse.y >= Y - 1 && mouse.y <  Y + lineWidth + 1 ){
			return 0;
		}
		return -1;
	}

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	


// graphic::