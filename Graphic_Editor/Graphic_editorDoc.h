
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

	// selector
public:
	int OIA[200];	// Object index Array
	int OIAC;
	int GIA[200];	// Groups index Array
	int GIAC;
	// .. data
public:
	graphic obj[200];
	int objC;
	Groups grp[200];
	int grpC;

	int DrawingFlag;
	int MMFlag;		// mouse move flag 0, 1
	int LbttnFlag;	// 0 := not down, 1 := now down
	int toolState;	// 0 := selector
					// 1 := line,	2 := polyline, 3 := ellipse,
					// 4 := rectangle,		5 := text
	COLORREF penColor, brushColor;
	int penSz, penStyle;
	int brushStyle;	// solid or hatch
	// method
	int addObj(int index);
};
