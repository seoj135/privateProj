#include "graphic.h"
#include "Graphic_editorView.h"
#include "Graphic_editorDoc.h"
#include "MainFrm.h"
// #include "1Line.cpp"
//

	// Creator, Destroyer
	//graphic::graphic(){ };	// ������		// Ư���� ���� ����
	//graphic::~graphic();		// �Ҹ���

	// ���� ������
	int graphic::create(int State)	
	{	
		// ���� ���õ��ִ� �ɼǵ��� �θ� �� �ֵ��� Document ��ü�� �ҷ�����

		// ��ɺ� ���� switch
		switch(State){
		case 0 :	// nothing

			return State;
		case 1 :	// Line

			return State;
		case 2 :	// PolyLine

			return State;
		case 3 :	// Rectangle

			return State;
		case 4 :	// Ellipse

			return State;
		case 5 :	// text

			return State;
		//case 6 :

		}
	}
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
	int graphic::selectPoint(CPoint mouse, int index)
	{	// point �� Ŭ���ϴ��� üũ
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
	int graphic::enGroup(){}
	int graphic::deGroup(){}
	int graphic::checkIn()
	{	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
		CGraphic_editorDoc* docu = (CGraphic_editorDoc*) pFrame->GetActiveDocument();
		for(int i=0; i<docu->grpC; i++){
		
		}
		for(int i=0; i<docu->objC; i++){

		}
	}

	// Line
	int graphic::inLine(CPoint mouse, CPoint startPoint, CPoint endPoint)
	{	// Line �� ���ϴ��� Ȯ��	// PolyLine ������ ���
		CPoint s = startPoint;		CPoint e = endPoint;
		if( (mouse.x <= s.x && mouse.x <= e.x) || (mouse.x >= s.x && mouse.x >= e.x) ) return -1;
		int Y;
		if( s.x != e.x ) Y = (e.y-s.y)/(e.x-s.x) * ( mouse.x - s.x ) + s.y - lineWidth/2; // ���� * ( X - s.x ) + s.y
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