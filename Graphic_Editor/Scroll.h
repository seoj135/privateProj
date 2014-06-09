#pragma once
#include "Graphic_editorDoc.h"
#include "graphic.h"

// CScroll 뷰입니다.

class CScroll : public CScrollView
{
	DECLARE_DYNCREATE(CScroll)

protected:
	CScroll();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CScroll();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual void OnInitialUpdate();     // 생성된 후 처음입니다.

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


