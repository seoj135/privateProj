class Graphics{
	// member variables
private:
	int inforState;		// 0 := nothing, 1 := line, 2 := polyline, 3 := ellipse,
						// 4 := rectangle, 5 := text, 6 := polygon
	CPoint* points;
	int pointNumber;	// �迭 index �ִ�ġ ����
	int lineWidth;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, �迭 index �ִ�ġ ����
		// ������ ��� ���� ���� ���� ���� ������ �߰��� ��
	
	// member functions
public:
	Graphics();		// ������
	int moveApoint(int index);
	int moveAll();
	int colorChange(COLORREF color);
	~Graphics();		// �Ҹ���
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