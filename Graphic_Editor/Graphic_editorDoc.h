
// Graphic_editorDoc.h : CGraphic_editorDoc Ŭ������ �������̽�
//


#pragma once
#include "graphic.h"

class CGraphic_editorDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CGraphic_editorDoc();
	DECLARE_DYNCREATE(CGraphic_editorDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CGraphic_editorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

	// .. data
public:
	graphic obj[200];
	Groups* grp;
	int objC;	
	int grpC;

	int DrawingFlag;// drawing~
	int MMFlag;		// mouse move flag 0, 1
	int LbttnFlag;	// 0 := not down, 1 := now down
	int toolState;	// 0 := selector
					// 1 := line,	2 := polyline, 3 := ellipse,
					// 4 := rectangle,		5 := text
	COLORREF lineColor, brushColor, bgColor, textColor, textBgColor;
	int lineSz, lineStyle;
	int brushStyle;	// solid or hatch, NULL	// 0, 1, 2

	int textBgFlag;	// 0 := solid or 1 := NULL
	int textSz;		// 8, 10, 12( ��ǻ�  15, 20, 25 )
	byte textWeight;	// FW_NORMAL 400 or FW_HEAVY 900
	byte textItalic, textUnderLine;	// 0, 1	// 0, 1
	int textType;	// ����, �ü�	// 0, 1
	// method
	int addObj();
	int delObj(int index);
};
