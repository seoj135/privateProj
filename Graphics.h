class Graphics{
	// member variables
private:
	int State;		// 0 := nothing or selector, 
					// 1 := line,		2 := polyline,		3 := ellipse,
					// 4 := rectangle,	5 := text,			6 := polygon	// Polygon 은 구현 미정
	CPoint* points;
	int pointNumber;	// 배열 index 최대치 관리
	int lineWidth;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, 배열 index 최대치 관리
		// 도형인 경우 내부 색에 대한 상태 변수를 추가할 것
	
	// Creator, Destroyer
public:
	Graphics();				// 생성자		// 특별한 구현 없음
	Graphics(int State);	// 생성자 2		// 실질적으로 사용함
	~Graphics();			// 소멸자
	//~Graphics(int State);	// 소멸자 2

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

	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
public:
	int selectPoint(CPoint mouse, int index);	// point 를 클릭하는지 체크

	// Line
public:
	int inLine(CPoint mouse, CPoint startPoint, CPoint endPoint);	// line 에 속한지 체크 // PolyLine 에서도 사용

	// PolyLine

	// Ellipse

	// Rectangle

	// Text	
private:
	CString textData; // ex) CString 변수
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