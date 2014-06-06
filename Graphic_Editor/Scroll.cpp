// Scroll.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Graphic_editor.h"
#include "Scroll.h"
//#include "Graphic_editorDoc.h"

// CScroll

IMPLEMENT_DYNCREATE(CScroll, CScrollView)

CScroll::CScroll()
	// :  CScrollView(CScroll::IDD)
{
}

CScroll::~CScroll()
{
}


BEGIN_MESSAGE_MAP(CScroll, CScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	//ON_WM_VSCROLL()
	//ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CScroll 그리기입니다.

void CScroll::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	
	CRect rc;
	GetClientRect(&rc);
	
	CSize sizeClient;
	sizeClient.cx = 800; //rc.right-rc.left;
	sizeClient.cy = 640; //rc.bottom-rc.top;
	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeClient.cx * 2;
	sizeTotal.cy = sizeClient.cy * 2;
	SetScrollSizes(MM_TEXT, sizeTotal, sizeClient);//, sizeClient);
}


// CScroll 진단입니다.

#ifdef _DEBUG
void CScroll::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CScroll::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CScroll 메시지 처리기입니다.
CGraphic_editorDoc* CScroll::GetDocument() const{
	return (CGraphic_editorDoc*) CView::GetDocument();
}

void CScroll::OnDraw(CDC* pDC)
{
	CGraphic_editorDoc* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	CClientDC dc(this);
	OnPrepareDC(&dc);	// For match logical grid in scroll view

	if(pDoc->MMFlag == 0){
		drawAll();
	}
	else {
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 : // line
			break;
		case 2 :	break;
		case 3 :	break;
		case 4 :	break;
		case 5 :	break;
		default: break;
		}
	}
}

int CScroll::drawAll(){
	// get doc
	CGraphic_editorDoc* pDoc = GetDocument();

	CClientDC dc(this);
	OnPrepareDC(&dc);

	CDC pDC;
	pDC.CreateCompatibleDC(&dc);
	OnPrepareDC(&pDC);
	CRect rect;		GetClientRect(&rect);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc /*&pDC*/, 800 * 2, 640 * 2);
	CBitmap* pBitmap = (CBitmap*) pDC.SelectObject(&bitmap);

	CBrush bgBrush(pDoc->bgColor);
	pDC.SelectObject(bgBrush);
	pDC.Rectangle(0, 0, 800 * 2, 640 * 2);

	CPen pen;
	CBrush brush;
	CFont font;
	for(int i=0; i<pDoc->objC; i++){
		// pen
		pen.CreatePen(pDoc->obj[i].getLineStyle(), pDoc->obj[i].getLineWidth(),  pDoc->obj[i].getColor(0));
		pDC.SelectObject(&pen);
		// brush
		switch(pDoc->obj[i].getHatch()){
		case 0: brush.CreateSolidBrush(pDoc->obj[i].getColor(2)); break;
		case 1: brush.CreateHatchBrush(2, pDoc->obj[i].getColor(2)); break;
		case 2: brush.CreateStockObject(NULL_BRUSH); break;
		}	pDC.SelectObject(&brush);
		// drawing
		switch(pDoc->obj[i].getState()){
		case 1 : // line
			pDC.MoveTo(pDoc->obj[i].getPoint(0));
			pDC.LineTo(pDoc->obj[i].getPoint(1));
			break;
		case 2 : // polyline
			pDC.MoveTo(pDoc->obj[i].getPoint(0));
			for(int j=1; j<pDoc->obj[i].getPointNumber(); j++){
				pDC.LineTo(pDoc->obj[i].getPoint(j));
				//m_dc.S
			}
			break;
		case 3 : // ellipse
			pDC.Ellipse(pDoc->obj[i].getPoint(0).x, pDoc->obj[i].getPoint(0).y, pDoc->obj[i].getPoint(1).x, pDoc->obj[i].getPoint(1).y);
			break;
		case 4 : // rectangle
			pDC.Rectangle(pDoc->obj[i].getPoint(0).x, pDoc->obj[i].getPoint(0).y, pDoc->obj[i].getPoint(1).x, pDoc->obj[i].getPoint(1).y);
			break;
		case 5 : // text
			// TO DO ..
			// font.
			break;
		default : break;
		}
	}
	dc.BitBlt(0, 0, 800 * 2, 640 * 2, &pDC, 0, 0, SRCCOPY);
	pDC.SelectObject(pBitmap);
	pDC.DeleteDC();
	bitmap.DeleteObject();
	return 0;
}


void CScroll::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// get doc
	CGraphic_editorDoc* pDoc = GetDocument();

	// .. Down
	if(pDoc->LbttnFlag == 0){
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 : // line
			break;
		case 2 :	break;
		case 3 :	break;
		case 4 :	break;
		case 5 :	break;
		// case 6 : break;
		default: break;
		}
	}
	CScrollView::OnLButtonDown(nFlags, point);
}


void CScroll::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// get doc
	CGraphic_editorDoc* pDoc = GetDocument();

	// .. Up
		if(pDoc->LbttnFlag == 1){
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 :	break;
		case 2 :	break;
		case 3 :	break;
		case 4 :	break;
		case 5 :	break;
		// case 6 : break;
		default: break;
		}
	}
	CScrollView::OnLButtonUp(nFlags, point);
}


void CScroll::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();

	// .. Move
	if(pDoc->DrawingFlag == 1){
		pDoc->MMFlag = 1;
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 :	break;
		case 2 :	break;
		case 3 :	break;
		case 4 :	break;
		case 5 :	break;
		// case 6 : break;
		default: break;
		}
	}
	CScrollView::OnMouseMove(nFlags, point);
}


void CScroll::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();

	if(pDoc->MMFlag == 1){	// mouse move 중일 때,
		// 그리기 취소 작업

		pDoc->MMFlag = 0;
		pDoc->DrawingFlag = 0;
	}
	CScrollView::OnRButtonUp(nFlags, point);
}

/*
void CScroll::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	drawAll();
	Invalidate();
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CScroll::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	drawAll();
	Invalidate();
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}
*/