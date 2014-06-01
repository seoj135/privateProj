#include "Graphics.h"
// #include "1Line.cpp"
//

// Creator, Destroyer
	Graphics::Graphics(){ };		// 생성자		// 특별한 구현 없음
	Graphics::Graphics(int State)	// 생성자 2		// 실질적으로 사용함
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
	Graphics::~Graphics();			// 소멸자
	//~Graphics(int State);	// 소멸자 2

	// mutator
	int Graphics::moveApoint(int index);
	int Graphics::moveAll();
	int Graphics::chgState(int a);
	int Graphics::addPoint(CPoint a);
	int Graphics::chgLineWidth(int a);
	int Graphics::chgLineStyle(int a);
	int Graphics::chgColor(COLORREF a);
	int Graphics::chgColorNumber(int a);

	// accessor
	int		 Graphics::getState()			{return State;}
	CPoint	 Graphics::getPoint(int index)	{return points[index];}
	int		 Graphics::getPointNumber()		{return pointNumber;}
	int		 Graphics::getLineWidth()		{return lineWidth;}
	int		 Graphics::getLineStyle()		{return lineStyle;}
	COLORREF Graphics::getColor(int index)	{return colors[index];}
	int		 Graphics::getColorNumber()		{return colorNumber;}

	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
	int Graphics::selectPoint(CPoint mouse, int index);	// point 를 클릭하는지 체크

	// Line
	int Graphics::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint);	// line 에 속한지 체크 // PolyLine 에서도 사용

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	