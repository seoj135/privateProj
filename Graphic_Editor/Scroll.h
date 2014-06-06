#pragma once
#include "Graphic_editorDoc.h"


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

public:
	CDC m_dc;
	int drawAll();
	CGraphic_editorDoc* GetDocument() const;

	// msg
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};


