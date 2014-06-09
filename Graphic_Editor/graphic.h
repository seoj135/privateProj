//#include<atltypes.h>	// CPoint
#pragma once
#include<afx.h>

class graphic{
	// member variables
private:
	int State;		// 0 := nothing, 
					// 1 := line,		2 := polyline,		3 := ellipse,
					// 4 := rectangle,	5 := text,			6 := polygon	// Polygon �� ���� ����
	CPoint points[40];
	int pointNumber;	// �迭 index �ִ�ġ ����
	int lineSz;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, �迭 index �ִ�ġ ����
		// ������ ��� ���� ���� ���� ���� ������ �߰��� ��
	int hatchFlag;	// 0 := solid, 1 := hatch, 2 := NULL
	// Creator, Destroyer
public:
	//graphic();			// ������		// Ư���� ���� ����
	//~graphic();			// �Ҹ���

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

	// ��Ÿ �ʿ��� ���� �� �޼ҵ���� �� �Ʒ��� �ּ� ���ٰ� �Բ� �߰��� ��
	// Selector
public:
	int selectPoint(CPoint mouse, int index);	// point �� Ŭ���ϴ��� üũ
	int enGroup();
	int deGroup();
	int checkIn(CPoint mouse, graphic o[200], int c);	// c = count
	CRect getLTRB(graphic o);
	// Line
public:
	int inLine(CPoint mouse, CPoint startPoint, CPoint endPoint, int lineSz);	// line �� ������ üũ // PolyLine ������ ���

	// PolyLine

	// Ellipse
	int inEllipse(CPoint mouse, CPoint startPoint, CPoint endPoint);
	// Rectangle
	int inRect(CPoint mouse, CPoint startPoint, CPoint endPoint); // text ������ ���
	// Text	
public:
	CString textData; // ex) CString ����
	byte textWeight, textItalic, textUnderLine;
	int fontSz, textType;
};

typedef struct structgrp{
	graphic obj[200];
} structGrp;

class Groups{	
	// document ������ �迭�� �����ϸ� �� ���� �ε��� ���� ������ ���� �� ��
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
};	// enGroup, deGroup method �� selector ���� 