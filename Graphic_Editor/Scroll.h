#pragma once
#include "Graphic_editorDoc.h"
#include "graphic.h"

// CScroll ���Դϴ�.

class CScroll : public CScrollView
{
	DECLARE_DYNCREATE(CScroll)

protected:
	CScroll();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CScroll();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual void OnInitialUpdate();     // ������ �� ó���Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	enum{ IDD = IDD_GRAPHIC_EDITOR_SCROLLVIEW };

	// selector
public:
	int OIA[200];	// Object index Array
	int OIAC;
	int GIA[200];	// Groups index Array
	int GIAC;
public:
	CPoint points[50];	// for polyline
	int pointNumber;
	int drawAll();
	CGraphic_editorDoc* GetDocument() const;

	// msg
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


