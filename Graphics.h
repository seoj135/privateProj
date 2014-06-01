class Graphics{
	// member variables
private:
	int State;		// 0 := nothing or selector, 
					// 1 := line,		2 := polyline,		3 := ellipse,
					// 4 := rectangle,	5 := text,			6 := polygon	// Polygon �� ���� ����
	CPoint* points;
	int pointNumber;	// �迭 index �ִ�ġ ����
	int lineWidth;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, �迭 index �ִ�ġ ����
		// ������ ��� ���� ���� ���� ���� ������ �߰��� ��
	
	// Creator, Destroyer
public:
	Graphics();				// ������		// Ư���� ���� ����
	Graphics(int State);	// ������ 2		// ���������� �����
	~Graphics();			// �Ҹ���
	//~Graphics(int State);	// �Ҹ��� 2

	// mutator
public:
	int moveApoint(int index);
	int moveAll();
	int chgState(int a);
	int addPoint(CPoint a);
	int chgLineWidth(int a);
	int chgLineStyle(int a);
	int chgColor(COLORREF a);
	int chgColorNumber(int a);

	// accessor
public:
	int		 getState();
	CPoint 	 getPoint(int index);
	int		 getPointNumber();
	int		 getLineWidth();
	int		 getLineStyle();
	COLORREF getColor(int index);
	int		 getColorNumber();

	// ��Ÿ �ʿ��� ���� �� �޼ҵ���� �� �Ʒ��� �ּ� ���ٰ� �Բ� �߰��� ��
	// Selector
public:
	int selectPoint(CPoint mouse, int index);	// point �� Ŭ���ϴ��� üũ

	// Line
public:
	int inLine(CPoint mouse, CPoint startPoint, CPoint endPoint);	// line �� ������ üũ // PolyLine ������ ���

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	
private:
	CString textData; // ex) CString ����
};

class Groups{	
	// document ������ �迭�� �����ϸ� �� ���� �ε��� ���� ������ ���� �� ��
private:	
	Grapics (*groupMembers)[200];
	Groups (*Groups)[200]
	int maxIndex;
public:
	Groups();
	int add(Grapics* addition);	// overriding
	int add(Groups* addition);	// overriding
	~Groups();
};