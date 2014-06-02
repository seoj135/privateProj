
// Graphic_editorView.h : CGraphic_editorView 클래스의 인터페이스
//

#pragma once

#include "resource.h"


class CGraphic_editorView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CGraphic_editorView();
	DECLARE_DYNCREATE(CGraphic_editorView)

public:
	enum{ IDD = IDD_GRAPHIC_EDITOR_FORM };

// 특성입니다.
public:
	CGraphic_editorDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CGraphic_editorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList5();
	afx_msg void OnCbnSelchangeCombo1();
};

#ifndef _DEBUG  // Graphic_editorView.cpp의 디버그 버전
inline CGraphic_editorDoc* CGraphic_editorView::GetDocument() const
   { return reinterpret_cast<CGraphic_editorDoc*>(m_pDocument); }
#endif

