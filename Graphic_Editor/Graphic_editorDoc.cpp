
// Graphic_editorDoc.cpp : CGraphic_editorDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Graphic_editor.h"
#include <afx.h>
#endif

#include "Graphic_editorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGraphic_editorDoc

IMPLEMENT_DYNCREATE(CGraphic_editorDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphic_editorDoc, CDocument)
END_MESSAGE_MAP()


// CGraphic_editorDoc 생성/소멸

CGraphic_editorDoc::CGraphic_editorDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	objC = grpC = 0;
	lineSz = 1;
	lineStyle = PS_SOLID;
	brushStyle = 0;
	textBgFlag = 0;	// 0, solid
	textSz = 15;
	textWeight = 400; //FW_NORMAL;	// FW_NORMAL 400 or FW_HEAVY 900
	textItalic = 0;		// 0 or 1
	textUnderLine = 0;	// 0 or 1
	textType = 0;
	DrawingFlag = MMFlag = LbttnFlag = 0;	// Flags
	lineColor = brushColor =  RGB(0, 0, 0);
	textColor = RGB(0, 255, 0);
	textBgColor = RGB(0, 0, 255);
	bgColor =  RGB(255, 255, 255);
	toolState = 0;
	/*	FS_BOLD			// 굵게
	FS_ITALIC           // 이탤릭 체
	FS_UNDERLINED       // 밑줄	*/
}

CGraphic_editorDoc::~CGraphic_editorDoc()
{
}

BOOL CGraphic_editorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGraphic_editorDoc serialization

void CGraphic_editorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

// method
int CGraphic_editorDoc::addObj(){
	// Point 는 따로 addPoint 를 이용하여 따로 추가한다
	obj[objC].chgState(toolState);
	obj[objC].chgLineSz(lineSz);
	obj[objC].chgLineStyle(lineStyle);
	if(toolState != 5){		obj[objC].chgColor(lineColor);}
	else {					obj[objC].chgColor(textColor);}
	
	if(toolState != 5){		obj[objC].chgColor2(brushColor);}
	else {					obj[objC].chgColor2(textBgColor);}
	
	if(toolState <= 2 || textBgFlag == 1){		obj[objC].chgColorNumber(1);}
	else {										obj[objC].chgColorNumber(2);}
	
	obj[objC].chgHatch(brushStyle);
	
	if(toolState == 5){
		obj[objC].fontSz = textSz;
		obj[objC].textData = _T("TEXT text");
		obj[objC].textWeight = textWeight;
		obj[objC].textItalic = textItalic;
		obj[objC].textUnderLine = textUnderLine;
		obj[objC].textType = textType;
	}
	objC++;	
	return 0;
}
int CGraphic_editorDoc::delObj(int index){
	if(index != objC){
		obj[index].chgState(obj[objC].getState());
		obj[index].chgLineSz(obj[objC].getLineSz());
		obj[index].chgLineStyle(obj[objC].getLineStyle());
		obj[index].chgColor(obj[objC].getColor(0)); // line or text color
		obj[index].chgColor2(obj[objC].getColor(1));
	
		obj[index].chgColorNumber(obj[objC].getColorNumber());
		obj[index].chgHatch(obj[objC].getHatch());
//		obj[index].chgTextStyle(obj[objC].getTextStyle());
		for(int i=0; i<obj[objC].getPointNumber(); i++){
			obj[index].chgPoint(i, obj[objC].getPoint(i));
		}
	}
	obj[index].chgState(0);
	objC--;
	return 0;
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CGraphic_editorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CGraphic_editorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CGraphic_editorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGraphic_editorDoc 진단

#ifdef _DEBUG
void CGraphic_editorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphic_editorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGraphic_editorDoc 명령
