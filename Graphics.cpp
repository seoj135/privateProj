#include "graphic.h"
// #include "1Line.cpp"
//

// Creator, Destroyer
	graphic::graphic(){ };		// ������		// Ư���� ���� ����
	graphic::graphic(int State)	// ������ 2		// ���������� �����
	{	
		// ���� ���õ��ִ� �ɼǵ��� �θ� �� �ֵ��� Document ��ü�� �ҷ�����

		// ��ɺ� ���� switch
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
	graphic::~graphic();			// �Ҹ���
	//~graphic(int State);	// �Ҹ��� 2

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

	// ��Ÿ �ʿ��� ���� �� �޼ҵ���� �� �Ʒ��� �ּ� ���ٰ� �Բ� �߰��� ��
	// Selector
	int graphic::selectPoint(CPoint mouse, int index)	// point �� Ŭ���ϴ��� üũ
	int enGroup()
	int deGroup()

	// Line
	int graphic::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint)	// line �� ������ üũ // PolyLine ������ ���

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	


// graphic::