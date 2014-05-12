class Graphics{
	// member variables
private:
	int inforState;		// 0 := nothing, 1 := line, 2 := polyline, 3 := ellipse,
						// 4 := rectangle, 5 := text, 6 := polygon
	CPoint* points;
	int pointNumber;	// 배열 index 최대치 관리
	int lineWidth;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, 배열 index 최대치 관리
		// 도형인 경우 내부 색에 대한 상태 변수를 추가할 것
	
	// member functions
public:
	Graphics();		// 생성자
	int moveApoint(int index);
	int moveAll();
	int colorChange(COLORREF color);
	~Graphics();		// 소멸자
};

class Groups{	
	// document 내에서 배열로 선언하며 이 역시 인덱스 관리 변수를 갖게 할 것
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