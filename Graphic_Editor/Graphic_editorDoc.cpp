
// Graphic_editorDoc.cpp : CGraphic_editorDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CGraphic_editorDoc ����/�Ҹ�

CGraphic_editorDoc::CGraphic_editorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
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
	/*	FS_BOLD			// ����
	FS_ITALIC           // ���Ÿ� ü
	FS_UNDERLINED       // ����	*/
}

CGraphic_editorDoc::~CGraphic_editorDoc()
{
}

BOOL CGraphic_editorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CGraphic_editorDoc serialization

void CGraphic_editorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

// method
int CGraphic_editorDoc::addObj(){
	// Point �� ���� addPoint �� �̿��Ͽ� ���� �߰��Ѵ�
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

// ����� �׸��� �����մϴ�.
void CGraphic_editorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CGraphic_editorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CGraphic_editorDoc ����

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


// CGraphic_editorDoc ���
