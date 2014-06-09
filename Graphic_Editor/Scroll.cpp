// Scroll.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Graphic_editor.h"
#include "Scroll.h"
//#include "Graphic_editorDoc.h"

// CScroll

IMPLEMENT_DYNCREATE(CScroll, CScrollView)

CScroll::CScroll()
{	pointNumber = 0;
}
CScroll::~CScroll()
{
}
BEGIN_MESSAGE_MAP(CScroll, CScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
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

	CPen pen;
	CBrush brush;
	CFont font;
	CRgn rgn;
	drawAll();
	dc.SetBkColor(pDoc->bgColor);
	if(pDoc->toolState == 0){
		//for(int 
	}
	if(pDoc->MMFlag){	// when mouse is moving
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 : // line
			pen.DeleteObject();
			pen.CreatePen(pDoc->lineStyle, pDoc->lineSz, pDoc->lineColor);
			dc.SelectObject(pen);
			dc.MoveTo(points[0]);
			dc.LineTo(points[1]);
			break;
		case 2 : // polyline
			pen.DeleteObject();
			pen.CreatePen(pDoc->lineStyle, pDoc->lineSz, pDoc->lineColor);
			dc.SelectObject(pen);
			dc.MoveTo(points[0]);
			for(int i=1; i<=pointNumber; i++){
				dc.LineTo(points[i]);
			}
			break;
		case 3 : // ellipse
			pen.DeleteObject();
			pen.CreatePen(pDoc->lineStyle, pDoc->lineSz, pDoc->lineColor);
			dc.SelectObject(pen);
			brush.DeleteObject();
			switch(pDoc->brushStyle){
			case 0: brush.CreateSolidBrush(pDoc->brushColor); break;
			case 1: brush.CreateHatchBrush(2, pDoc->brushColor); break;
			case 2: brush.CreateStockObject(NULL_BRUSH); break;
			}	dc.SelectObject(&brush);
			
			dc.Ellipse(points[0].x, points[0].y, points[1].x, points[1].y);
			break;
		case 4 : // rectangle
			pen.DeleteObject();
			pen.CreatePen(pDoc->lineStyle, pDoc->lineSz, pDoc->lineColor);
			dc.SelectObject(pen);
			brush.DeleteObject();
			switch(pDoc->brushStyle){
			case 0: brush.CreateSolidBrush(pDoc->brushColor); break;
			case 1: brush.CreateHatchBrush(2, pDoc->brushColor); break;
			case 2: brush.CreateStockObject(NULL_BRUSH); break;
			}	dc.SelectObject(&brush);

			dc.Rectangle(points[0].x, points[0].y, points[1].x, points[1].y);
			break;
		case 5 : // text
			pen.DeleteObject();
			pen.CreateStockObject(NULL_PEN);
			dc.SelectObject(pen);
			brush.DeleteObject();
			if(pDoc->textBgFlag == 1)	brush.CreateStockObject(NULL_BRUSH);
			else						brush.CreateSolidBrush(pDoc->textBgColor);
			dc.SelectObject(brush);
			dc.Rectangle(points[0].x, points[0].y, points[1].x, points[1].y);
			
			if(pDoc->textBgFlag == 0) dc.SetBkColor(pDoc->textBgColor);
			dc.SetTextColor(pDoc->textColor);
			font.DeleteObject();
			font.CreateFontW(pDoc->textSz, 0, 0, 0, 
				/**/ pDoc->textWeight,/**/ pDoc->textItalic,/**/ pDoc->textUnderLine
				, 0, 0, 0, 0, 0, 0, (pDoc->textType) ? _T("궁서") : _T("굴림") ); // 1 := 궁서, 0 := 굴림
			dc.SelectObject(font);
			rgn.DeleteObject();
			rgn.CreateRectRgn(points[0].x, points[0].y, points[1].x, points[1].y);
			dc.SelectClipRgn(&rgn);
			dc.TextOutW(points[0].x + 2, points[0].y, _T("TEXT text"));
			
			break;
		default: break;
		}
	}
	pen.DeleteObject();
	brush.DeleteObject();
	font.DeleteObject();
	rgn.DeleteObject();
}


void CScroll::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// get doc
	CGraphic_editorDoc* pDoc = GetDocument();

	// .. Down
	if(pDoc->LbttnFlag == 0){
		switch(pDoc->toolState){
		case 0 : // selector
			{	int value = 0;// = dummy->checkIn(point, dummy);
				if(value != -1){
					// select
					if( ! (nFlags & VK_CONTROL) ){

					}
					else { // multi- select
						
					}
				}
			}
			break;
		case 1 : // line
			if(pDoc->DrawingFlag == 0){ // start point
				points[pDoc->DrawingFlag] = point; // points[0]
				pointNumber++;
				pDoc->DrawingFlag++;
			}
			else {	// endPoint
				points[pDoc->DrawingFlag] = point; // points[1]
				pDoc->obj[pDoc->objC].initPN();
				pDoc->obj[pDoc->objC].addPoint(points[0]);
				pDoc->obj[pDoc->objC].addPoint(points[1]);
				pDoc->addObj();
				pointNumber = 0;
				pDoc->DrawingFlag = 0;
				pDoc->MMFlag = 0;
			}
			break;
		case 2 : // polyline // LdoubleClick 으로 끝내야함
			if(pDoc->DrawingFlag < 40){ // start point
				points[pDoc->DrawingFlag] = point;
				pointNumber++;
				pDoc->DrawingFlag++;
			}
			break;
		case 3 : // ellipse
			if(pDoc->DrawingFlag == 0){ // start point
				points[pDoc->DrawingFlag] = point; // points[0]
				pointNumber++;
				pDoc->DrawingFlag++;
			}
			else {	// endPoint
				points[pDoc->DrawingFlag] = point; // points[1]
				pDoc->obj[pDoc->objC].initPN();
				pDoc->obj[pDoc->objC].addPoint(points[0]);
				pDoc->obj[pDoc->objC].addPoint(points[1]);
				pDoc->addObj();
				pointNumber = 0;
				pDoc->DrawingFlag = 0;
				pDoc->MMFlag = 0;
			}
			break;
		case 4 : // rectangle
			if(pDoc->DrawingFlag == 0){ // start point
				points[pDoc->DrawingFlag] = point; // points[0]
				pointNumber++;
				pDoc->DrawingFlag++;
			}
			else {	// endPoint
				points[pDoc->DrawingFlag] = point; // points[1]
				pDoc->obj[pDoc->objC].initPN();
				pDoc->obj[pDoc->objC].addPoint(points[0]);
				pDoc->obj[pDoc->objC].addPoint(points[1]);
				pDoc->addObj();
				pointNumber = 0;
				pDoc->DrawingFlag = 0;
				pDoc->MMFlag = 0;
			}
			break;
		case 5 : // text
			if(pDoc->DrawingFlag == 0){ // start point
				points[pDoc->DrawingFlag] = point; // points[0]
				pointNumber++;
				pDoc->DrawingFlag++;
			}
			else {	// endPoint
				if(point.x >= points[0].x)
					points[1].x = point.x;
				else {
					pDoc->MMFlag = 0;		// cancel
					pDoc->DrawingFlag = 0;
					pointNumber = 0;
					Invalidate();	break;
				}
				points[1].y = points[0].y + pDoc->textSz + 2; // points[1]
				pDoc->obj[pDoc->objC].initPN();
				pDoc->obj[pDoc->objC].addPoint(points[0]);
				pDoc->obj[pDoc->objC].addPoint(points[1]);
				/**/ 
				pDoc->addObj();
				pointNumber = 0;
				pDoc->DrawingFlag = 0;
				pDoc->MMFlag = 0;
			}
			break;
		default: break;
		}
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CScroll::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();
	
	CClientDC dc(this);
	// .. Move
	if(pDoc->DrawingFlag >= 1){
		pDoc->MMFlag = 1;
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 : // line			
			points[1] = point;
			break;
		case 2 : // polyline
			points[pointNumber] = point;
			break;
		case 3 : // ellipse
			points[1] = point;
			break;
		case 4 : // rectangle
			points[1] = point;
			break;
		case 5 : // text
			if(point.x >= points[0].x)
				points[1].x = point.x;
			else points[1].x = points[0].x;
			points[1].y = points[0].y + pDoc->textSz + 2; // points[1]
			break;
		default: break;
		}
		Invalidate();
	}
	CScrollView::OnMouseMove(nFlags, point);
}

void CScroll::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// get doc
	CGraphic_editorDoc* pDoc = GetDocument();

	// .. Up	// not used
	if(pDoc->LbttnFlag == 1){
		switch(pDoc->toolState){
		case 0 :	break;
		case 1 :	break;
		case 2 :	break;
		case 3 :	break;
		case 4 :	break;
		case 5 :	break;
		default: break;
		}
	}
	CScrollView::OnLButtonUp(nFlags, point);
}

// cancel
void CScroll::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();

	if(pDoc->MMFlag == 1){	// mouse move 중일 때,
		// 그리기 취소 작업
		pDoc->MMFlag = 0;
		pDoc->DrawingFlag = 0;
		pointNumber = 0;
		Invalidate();
	}
	CScrollView::OnRButtonDown(nFlags, point);
}

// drawAll()
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
	CRgn rgn;
	CRgn rgn2;
	for(int i=pDoc->objC-1; i>=0; i--){
		// pen
		pen.DeleteObject();
		pen.CreatePen(pDoc->obj[i].getLineStyle(), pDoc->obj[i].getLineSz(),  pDoc->obj[i].getColor(0));
		pDC.SelectObject(&pen);
		// brush
		brush.DeleteObject();
		switch(pDoc->obj[i].getHatch()){
		case 0: brush.CreateSolidBrush(pDoc->obj[i].getColor(1)); break;
		case 1: brush.CreateHatchBrush(2, pDoc->obj[i].getColor(1)); break;
		case 2: brush.CreateStockObject(NULL_BRUSH); break;
		}	pDC.SelectObject(&brush);
		pDC.SetBkColor(pDoc->bgColor);
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
			pen.DeleteObject();
			pen.CreateStockObject(NULL_PEN);
			pDC.SelectObject(pen);
			brush.DeleteObject();
			if(pDoc->obj[i].getColorNumber() == 1)	brush.CreateStockObject(NULL_BRUSH);
			else									brush.CreateSolidBrush(pDoc->obj[i].getColor(1));
			//if(pDoc->textBgFlag == 1)	brush.CreateStockObject(NULL_BRUSH);
			//else						brush.CreateSolidBrush(pDoc->textBgColor);
			pDC.SelectObject(brush);
			pDC.Rectangle(pDoc->obj[i].getPoint(0).x, pDoc->obj[i].getPoint(0).y, pDoc->obj[i].getPoint(1).x, pDoc->obj[i].getPoint(1).y);
				
			if(pDoc->obj[i].getColorNumber() == 2) pDC.SetBkColor(pDoc->obj[i].getColor(1));
			pDC.SetTextColor(pDoc->obj[i].getColor(0));
			font.DeleteObject();
			font.CreateFontW(pDoc->obj[i].fontSz, 0, 0, 0, 
				/**/ pDoc->obj[i].textWeight,/**/ pDoc->obj[i].textItalic,/**/ pDoc->obj[i].textUnderLine
				, 0, 0, 0, 0, 0, 0, (pDoc->obj[i].textType) ? _T("궁서") : _T("굴림") ); // 1 := 궁서, 0 := 굴림
			pDC.SelectObject(font);
			rgn.DeleteObject();
			rgn.CreateRectRgn(pDoc->obj[i].getPoint(0).x, pDoc->obj[i].getPoint(0).y, pDoc->obj[i].getPoint(1).x, pDoc->obj[i].getPoint(1).y);
			pDC.SelectClipRgn(&rgn);
			pDC.TextOutW(pDoc->obj[i].getPoint(0).x + 2, pDoc->obj[i].getPoint(0).y, pDoc->obj[i].textData);
			rgn2.DeleteObject();
			rgn2.CreateRectRgnIndirect(&rect);
			pDC.SelectClipRgn(&rgn2);
			break;
		default : break;
		}
	}
	dc.BitBlt(0, 0, 800 * 2, 640 * 2, &pDC, 0, 0, SRCCOPY);
	pDC.SelectObject(pBitmap);
	pDC.DeleteDC();
	bitmap.DeleteObject();
	rgn.DeleteObject();
	rgn2.DeleteObject();
	font.DeleteObject();
	pen.DeleteObject();
	brush.DeleteObject();
	bgBrush.DeleteObject();
	return 0;
}

void CScroll::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();

	// polyline 종료시에 사용됨 // polyline endpoint
	if(pDoc->toolState == 2 && pDoc->DrawingFlag >= 2){
		pDoc->obj[pDoc->objC].initPN();
		for(int i=0; i<pointNumber; i++){
			pDoc->obj[pDoc->objC].addPoint(points[i]);
		}
		pDoc->addObj();
		pDoc->DrawingFlag = 0;
		pDoc->MMFlag = 0;
		pointNumber = 0;
		Invalidate();
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CScroll::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphic_editorDoc* pDoc = GetDocument();
	// VK_DELETE, a, s, d, f, g, h
	switch(nChar){
	case VK_DELETE :MessageBox(_T("ASD"), _T("ASD"), NULL);
		break;
	// tool key
	case 'a' : // selector
	case 'A' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 0; break;
	case 's' : // line
	case 'S' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 1; break;
	case 'd' : // polyline
	case 'D' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 2; break;
	case 'f' : // ellipse
	case 'F' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 3; break;
	case 'g' : // rectangle
	case 'G' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 4; break;
	case 'h' : // text
	case 'H' :
		if(pDoc->DrawingFlag == 0) pDoc->toolState = 5; break;
	// Clipboard
	case 'x' : // cut
	case 'X' :
		break;
	case 'c' : // copy
	case 'C' :
		break;
	case 'v' : // paste
	case 'V' :
		break;
	default: break;
	}
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CScroll::OnEraseBkgnd(CDC* pDC)
{
	return false;
}