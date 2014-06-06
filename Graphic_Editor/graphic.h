//#include<atltypes.h>	// CPoint
#pragma once
#include<afx.h>

class graphic{
	// member variables
private:
	int State;		// 0 := nothing, 
					// 1 := line,		2 := polyline,		3 := ellipse,
					// 4 := rectangle,	5 := text,			6 := polygon	// Polygon �� ���� ����
	CPoint* points;
	int pointNumber;	// �迭 index �ִ�ġ ����
	int lineWidth;		// lineWidth
	int lineStyle;		// lineStyle
	COLORREF colors[2];
	int colorNumber;	// 1 or 2, �迭 index �ִ�ġ ����
		// ������ ��� ���� ���� ���� ���� ������ �߰��� ��
	int hatchFlag;	// 0 := solid, 1 := hatch
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
	int chgLineWidth(int a);
	int chgLineStyle(int a);
	int chgColor(COLORREF a);
	int chgColor2(COLORREF a);
	int chgColorNumber(int a);
	int chgHatch(int a);

	// accessor
public:
	int		 getState();
	CPoint 	 getPoint(int index);
	int		 getPointNumber();
	int		 getLineWidth();
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
	int checkIn(CPoint mouse, graphic o[200]);
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

typedef struct structgrp{
	graphic obj[200];
} structGrp;

class Groups{	
	// document ������ �迭�� �����ϸ� �� ���� �ε��� ���� ������ ���� �� ��
public:	
	graphic obj[200];
	structGrp grp[200];
	int graphicNum;
	int GroupNum;
public:
	//Groups();
	//~Groups();
	int add1(graphic addition);	
	int add2(Groups addition);
	int cancel();
};	// enGroup, deGroup method �� selector ���� 