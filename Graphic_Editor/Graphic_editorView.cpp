
// Graphic_editorView.cpp : CGraphic_editorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CGraphic_editorView 생성/소멸

CGraphic_editorView::CGraphic_editorView()
	: CFormView(CGraphic_editorView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CGraphic_editorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CGraphic_editorView 진단

#ifdef _DEBUG
void CGraphic_editorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGraphic_editorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGraphic_editorDoc* CGraphic_editorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphic_editorDoc)));
	return (CGraphic_editorDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphic_editorView 메시지 처리기


void CGraphic_editorView::OnLbnSelchangeList5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CGraphic_editorView::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
