
// Graphic_editorView.h : CGraphic_editorView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"


class CGraphic_editorView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CGraphic_editorView();
	DECLARE_DYNCREATE(CGraphic_editorView)

public:
	enum{ IDD = IDD_GRAPHIC_EDITOR_FORM };

// Ư���Դϴ�.
public:
	CGraphic_editorDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CGraphic_editorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList5();
	afx_msg void OnCbnSelchangeCombo1();
};

#ifndef _DEBUG  // Graphic_editorView.cpp�� ����� ����
inline CGraphic_editorDoc* CGraphic_editorView::GetDocument() const
   { return reinterpret_cast<CGraphic_editorDoc*>(m_pDocument); }
#endif

