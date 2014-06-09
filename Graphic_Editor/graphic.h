//#include<atltypes.h>	// CPoint
#pragma once
#include<afx.h>

class graphic{
	// member variables
private:
	int State;		// 0 := nothing, 
					// 1 := line,		2 := polyline,		3 := ellipse,
					// 4 := rectangle,	5 := text,			6 := polygon	// Polygon 은 구현 미정
	CPoint points[40];
	int pointNumber;	// 배열 index 최대치 관리
	int lineSz;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, 배열 index 최대치 관리
		// 도형인 경우 내부 색에 대한 상태 변수를 추가할 것
	int hatchFlag;	// 0 := solid, 1 := hatch, 2 := NULL
	// Creator, Destroyer
public:
	//graphic();			// 생성자		// 특별한 구현 없음
	//~graphic();			// 소멸자

	// mutator
public:
	int moveApoint(int index, CPoint dest);
	int moveAll(CPoint base, CPoint dest);
	int chgState(int a);
	int addPoint(CPoint a);
	int chgPoint(int index, CPoint a);
	int chgLineSz(int a);
	int chgLineStyle(int a);
	int chgColor(COLORREF a);
	int chgColor2(COLORREF a);
	int chgColorNumber(int a);
	int chgHatch(int a);
	int initPN();
	// accessor
public:
	int		 getState();
	CPoint 	 getPoint(int index);
	int		 getPointNumber();
	int		 getLineSz();
	int		 getLineStyle();
	COLORREF getColor(int index);
	int		 getColorNumber();
	int		 getHatch();

	// 기타 필요한 변수 및 메소드들은 이 아래로 주석 한줄과 함께 추가할 것
	// Selector
public:
	int selectPoint(CPoint mouse, int index);	// point 를 클릭하는지 체크
	int enGroup();
	int deGroup();
	int checkIn(CPoint mouse, graphic o[200], int c);	// c = count
	CRect getLTRB(graphic o);
	// Line
public:
	int inLine(CPoint mouse, CPoint startPoint, CPoint endPoint, int lineSz);	// line 에 속한지 체크 // PolyLine 에서도 사용

	// PolyLine

	// Ellipse
	int inEllipse(CPoint mouse, CPoint startPoint, CPoint endPoint);
	// Rectangle
	int inRect(CPoint mouse, CPoint startPoint, CPoint endPoint); // text 에서도 사용
	// Text	
public:
	CString textData; // ex) CString 변수
	byte textWeight, textItalic, textUnderLine;
	int fontSz, textType;
};

typedef struct structgrp{
	graphic obj[200];
} structGrp;

class Groups{	
	// document 내에서 배열로 선언하며 이 역시 인덱스 관리 변수를 갖게 할 것
public:	
	CRect rect;	// reft, top, right, bot
	int depth;
	graphic obj[200];
	Groups **grp;
	int objC;
	int grpC;
public:
	Groups();
	Groups(int i_depth);
	//~Groups();
	int add1(graphic addition);	
	int add2(Groups addition);
	int cancel();
	int makeGrp(int c);		// c : count
	CPoint grpCheckin(CPoint mouse, Groups grp[], int c);	// c : count
	CRect getLTRB();
};	// enGroup, deGroup method 는 selector 에서 