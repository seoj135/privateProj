#include "graphic.h"
// #include "1Line.cpp"
//

// Creator, Destroyer
	graphic::graphic(){ };		// 생성자		// 특별한 구현 없음
	graphic::graphic(int State)	// 생성자 2		// 실질적으로 사용함
	{	
		// 현재 선택되있는 옵션들을 부를 수 있도록 Document 객체를 불러야함

		// 기능별 구현 switch
		switch(State){
		case 0 :	// nothing

			break;
		case 1 :	// Line

			break;
		case 2 :	// PolyLine

			break;
		case 3 :	// Rectangle

			break;
		case 4 :	// Ellipse

			break;
		case 5 :	// text

			break;
		//case 6 :

		}
	}
	graphic::~graphic();			// 소멸자
	//~graphic(int State);	// 소멸자 2

	// mutator
	int graphic::moveApoint(int index, CPoint dest)
	{	points[index] = dest;	return 0;			}
	int graphic::moveAll(CPoint base, CPoint dest)
	{	for(int i=0; i<pointNumber; i++)
			points[index] += (dest - index);
		return 0;									}
	int graphic::chgState(int a)		{State = a; return 0;}
	int graphic::addPoint(CPoint a)		{points[++pointNumber] = a; return 0;}
	int graphic::chgLineWidth(int a)	{lineWidth = a; return 0;}
	int graphic::chgLineStyle(int a)	{lineStyle = a; return 0;}
	int graphic::chgColor(COLORREF a)	{colors[0] = a; return 0;}
	int graphic::chgColor2(COLORREF a)	{colors[1] = a; return 0;}
	int graphic::chgColorNumber(int a)	{colorNumber = a; return 0;}

	// accessor
	int		 graphic::getState()			{return State;}
	CPoint	 graphic::getPoint(int index)	{return points[index];}
	int		 graphic::getPointNumber()		{return pointNumber;}
	int		 graphic::getLineWidth()		{return lineWidth;}
	int		 graphic::getLineStyle()		{return lineStyle;}
	COLORREF graphic::getColor(int index)	{return colors[index];}
	int		 graphic::getColorNumber()		{return colorNumber;}

	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
	int graphic::selectPoint(CPoint mouse, int index)	// point 를 클릭하는지 체크
	int enGroup()
	int deGroup()

	// Line
	int graphic::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint)	// line 에 속한지 체크 // PolyLine 에서도 사용

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	


// graphic::