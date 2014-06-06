
// Graphic_editorView.cpp : CGraphic_editorView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Graphic_editor.h"
#endif

#include "Graphic_editorDoc.h"
#include "Graphic_editorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphic_editorView

IMPLEMENT_DYNCREATE(CGraphic_editorView, CFormView)

BEGIN_MESSAGE_MAP(CGraphic_editorView, CFormView)

END_MESSAGE_MAP()

// CGraphic_editorView ����/�Ҹ�

CGraphic_editorView::CGraphic_editorView()
	: CFormView(CGraphic_editorView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CGraphic_editorView::~CGraphic_editorView()
{
}

void CGraphic_editorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CGraphic_editorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CGraphic_editorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CGraphic_editorView ����

#ifdef _DEBUG
void CGraphic_editorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGraphic_editorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGraphic_editorDoc* CGraphic_editorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphic_editorDoc)));
	return (CGraphic_editorDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphic_editorView �޽��� ó����


void CGraphic_editorView::OnLbnSelchangeList5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CGraphic_editorView::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
