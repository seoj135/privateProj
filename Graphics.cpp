#include "Graphics.h"
// #include "1Line.cpp"
//

// Creator, Destroyer
	Graphics::Graphics(){ };		// ������		// Ư���� ���� ����
	Graphics::Graphics(int State)	// ������ 2		// ���������� �����
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
	Graphics::~Graphics();			// �Ҹ���
	//~Graphics(int State);	// �Ҹ��� 2

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

	// ��Ÿ �ʿ��� ���� �� �޼ҵ���� �� �Ʒ��� �ּ� ���ٰ� �Բ� �߰��� ��
	// Selector
	int Graphics::selectPoint(CPoint mouse, int index);	// point �� Ŭ���ϴ��� üũ

	// Line
	int Graphics::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint);	// line �� ������ üũ // PolyLine ������ ���

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	