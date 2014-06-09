#include "stdafx.h"
#include "Graphic_editor.h"
#include "MainFrm.h"
#include "Graphic_editorDoc.h"
#include "Scroll.h"
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()	// create
	// clipboard
	ON_COMMAND(ID_EDIT_CUT, &CMainFrame::OnEditCut)						// clipboard .s
	ON_COMMAND(ID_EDIT_COPY, &CMainFrame::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CMainFrame::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CMainFrame::OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CMainFrame::OnUpdateEditPaste)	// clipboard .e

	// tool
	ON_COMMAND(ID_MOUSE, &CMainFrame::OnMouse)							// tools .s
	ON_UPDATE_COMMAND_UI(ID_MOUSE, &CMainFrame::OnUpdateMouse)
	ON_COMMAND(ID_LINE, &CMainFrame::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMainFrame::OnUpdateLine)
	ON_COMMAND(ID_POLYLINE, &CMainFrame::OnPolyline)
	ON_UPDATE_COMMAND_UI(ID_POLYLINE, &CMainFrame::OnUpdatePolyline)
	ON_COMMAND(ID_RECTANGLE, &CMainFrame::OnRectangle)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CMainFrame::OnUpdateRectangle)
	ON_COMMAND(ID_CIRCLE, &CMainFrame::OnCircle)
	ON_UPDATE_COMMAND_UI(ID_CIRCLE, &CMainFrame::OnUpdateCircle)
	ON_COMMAND(ID_TEXT, &CMainFrame::OnText)
	ON_UPDATE_COMMAND_UI(ID_TEXT, &CMainFrame::OnUpdateText)			// tools .e

	// line
	ON_COMMAND(ID_LINE_COLOR, &CMainFrame::OnLineColor)					// line Color .s
	ON_UPDATE_COMMAND_UI(ID_LINE_COLOR, &CMainFrame::OnUpdateLineColor)
	ON_COMMAND(ID_LINE_BLACK, &CMainFrame::OnLineBlack)
	ON_UPDATE_COMMAND_UI(ID_LINE_BLACK, &CMainFrame::OnUpdateLineBlack)
	ON_COMMAND(ID_LINE_RED, &CMainFrame::OnLineRed)
	ON_UPDATE_COMMAND_UI(ID_LINE_RED, &CMainFrame::OnUpdateLineRed)
	ON_COMMAND(ID_LINE_GREEN, &CMainFrame::OnLineGreen)
	ON_UPDATE_COMMAND_UI(ID_LINE_GREEN, &CMainFrame::OnUpdateLineGreen)
	ON_COMMAND(ID_LINE_BLUE, &CMainFrame::OnLineBlue)
	ON_UPDATE_COMMAND_UI(ID_LINE_BLUE, &CMainFrame::OnUpdateLineBlue)
	ON_COMMAND(ID_LINE_WHITE, &CMainFrame::OnLineWhite)
	ON_UPDATE_COMMAND_UI(ID_LINE_WHITE, &CMainFrame::OnUpdateLineWhite)	// line color .e
	
	ON_COMMAND(ID_LINE_SOLID, &CMainFrame::OnLineSolid)					// line Style .s
	ON_UPDATE_COMMAND_UI(ID_LINE_SOLID, &CMainFrame::OnUpdateLineSolid) 
	ON_COMMAND(ID_LINE_DASH, &CMainFrame::OnLineDash)
	ON_UPDATE_COMMAND_UI(ID_LINE_DASH, &CMainFrame::OnUpdateLineDash)
	ON_COMMAND(ID_LINE_NULL, &CMainFrame::OnLineNull)
	ON_UPDATE_COMMAND_UI(ID_LINE_NULL, &CMainFrame::OnUpdateLineNull)	// line Style .e

	ON_COMMAND(ID_LINE_THIN, &CMainFrame::OnLineThin)						// line Sz .s
	ON_UPDATE_COMMAND_UI(ID_LINE_THIN, &CMainFrame::OnUpdateLineThin)
	ON_COMMAND(ID_LINE_NORMAL, &CMainFrame::OnLineNormal)
	ON_UPDATE_COMMAND_UI(ID_LINE_NORMAL, &CMainFrame::OnUpdateLineNormal)
	ON_COMMAND(ID_LINE_THICK, &CMainFrame::OnLineThick)
	ON_UPDATE_COMMAND_UI(ID_LINE_THICK, &CMainFrame::OnUpdateLineThick)		// line Sz .e

	// brush
	ON_COMMAND(ID_FACE_COLOR, &CMainFrame::OnFaceColor)					// brush color .s
	ON_UPDATE_COMMAND_UI(ID_FACE_COLOR, &CMainFrame::OnUpdateFaceColor)
	ON_COMMAND(ID_FACE_BLACK, &CMainFrame::OnFaceBlack)					
	ON_UPDATE_COMMAND_UI(ID_FACE_BLACK, &CMainFrame::OnUpdateFaceBlack)
	ON_COMMAND(ID_FACE_RED, &CMainFrame::OnFaceRed)
	ON_UPDATE_COMMAND_UI(ID_FACE_RED, &CMainFrame::OnUpdateFaceRed)
	ON_COMMAND(ID_FACE_GREEN, &CMainFrame::OnFaceGreen)
	ON_UPDATE_COMMAND_UI(ID_FACE_GREEN, &CMainFrame::OnUpdateFaceGreen)
	ON_COMMAND(ID_FACE_BLUE, &CMainFrame::OnFaceBlue)
	ON_UPDATE_COMMAND_UI(ID_FACE_BLUE, &CMainFrame::OnUpdateFaceBlue)
	ON_COMMAND(ID_FACE_WHITE, &CMainFrame::OnFaceWhite)
	ON_UPDATE_COMMAND_UI(ID_FACE_WHITE, &CMainFrame::OnUpdateFaceWhite)	// brush color .e

	ON_COMMAND(ID_SOLID, &CMainFrame::OnSolid)							// brush style .s
	ON_UPDATE_COMMAND_UI(ID_SOLID, &CMainFrame::OnUpdateSolid)
	ON_COMMAND(ID_HATCH, &CMainFrame::OnHatch)
	ON_UPDATE_COMMAND_UI(ID_HATCH, &CMainFrame::OnUpdateHatch)
	ON_COMMAND(ID_NULL, &CMainFrame::OnNull)
	ON_UPDATE_COMMAND_UI(ID_NULL, &CMainFrame::OnUpdateNull)			// brush style. e

	// font
	ON_COMMAND(ID_TEXT_COLOR, &CMainFrame::OnTextColor)					// font color .s
	ON_UPDATE_COMMAND_UI(ID_TEXT_COLOR, &CMainFrame::OnUpdateTextColor)
	ON_COMMAND(ID_TEXT_BLACK, &CMainFrame::OnTextBlack)					
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLACK, &CMainFrame::OnUpdateTextBlack)
	ON_COMMAND(ID_TEXT_RED, &CMainFrame::OnTextRed)
	ON_UPDATE_COMMAND_UI(ID_TEXT_RED, &CMainFrame::OnUpdateTextRed)
	ON_COMMAND(ID_TEXT_GREEN, &CMainFrame::OnTextGreen)
	ON_UPDATE_COMMAND_UI(ID_TEXT_GREEN, &CMainFrame::OnUpdateTextGreen)
	ON_COMMAND(ID_TEXT_BLUE, &CMainFrame::OnTextBlue)
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLUE, &CMainFrame::OnUpdateTextBlue)
	ON_COMMAND(ID_TEXT_WHITE, &CMainFrame::OnTextWhite)
	ON_UPDATE_COMMAND_UI(ID_TEXT_WHITE, &CMainFrame::OnUpdateTextWhite)	// font color .e

	ON_COMMAND(ID_TEXT_B_COLOR, &CMainFrame::OnTextBColor)					// font bg color .s
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_COLOR, &CMainFrame::OnUpdateTextBColor)
	ON_COMMAND(ID_TEXT_B_BLACK, &CMainFrame::OnTextBBlack)					
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_BLACK, &CMainFrame::OnUpdateTextBBlack)
	ON_COMMAND(ID_TEXT_B_RED, &CMainFrame::OnTextBRed)
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_RED, &CMainFrame::OnUpdateTextBRed)
	ON_COMMAND(ID_TEXT_B_GREEN, &CMainFrame::OnTextBGreen)
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_GREEN, &CMainFrame::OnUpdateTextBGreen)
	ON_COMMAND(ID_TEXT_B_BLUE, &CMainFrame::OnTextBBlue)
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_BLUE, &CMainFrame::OnUpdateTextBBlue)
	ON_COMMAND(ID_TEXT_B_WHITE, &CMainFrame::OnTextBWhite)
	ON_UPDATE_COMMAND_UI(ID_TEXT_B_WHITE, &CMainFrame::OnUpdateTextBWhite)	
	ON_COMMAND(ID_TEXTBGNULL, &CMainFrame::OnTextbgnull)
	ON_UPDATE_COMMAND_UI(ID_TEXTBGNULL, &CMainFrame::OnUpdateTextbgnull)// font bg color .e

	ON_COMMAND(ID_TEXT_THICK, &CMainFrame::OnTextThick)						// font style .s
	ON_UPDATE_COMMAND_UI(ID_TEXT_THICK, &CMainFrame::OnUpdateTextThick)
	ON_COMMAND(ID_TEXT_UNDERLINE, &CMainFrame::OnTextUnderline)
	ON_UPDATE_COMMAND_UI(ID_TEXT_UNDERLINE, &CMainFrame::OnUpdateTextUnderline)
	ON_COMMAND(ID_TEXT_TILT, &CMainFrame::OnTextTilt)
	ON_UPDATE_COMMAND_UI(ID_TEXT_TILT, &CMainFrame::OnUpdateTextTilt)		
	ON_COMMAND(ID_T_init, &CMainFrame::OnTInit)								// font style .e

	ON_COMMAND(ID_T8, &CMainFrame::OnT8)							// text sz	.s
	ON_UPDATE_COMMAND_UI(ID_T8, &CMainFrame::OnUpdateT8)
	ON_COMMAND(ID_T10, &CMainFrame::OnT10)
	ON_UPDATE_COMMAND_UI(ID_T10, &CMainFrame::OnUpdateT10)
	ON_COMMAND(ID_T12, &CMainFrame::OnT12)
	ON_UPDATE_COMMAND_UI(ID_T12, &CMainFrame::OnUpdateT12)			// text sz	.e
	
	ON_COMMAND(ID_font1, &CMainFrame::OnFont1)						// text type .s // 굴림
	ON_UPDATE_COMMAND_UI(ID_font1, &CMainFrame::OnUpdateFont1)
	ON_COMMAND(ID_font2, &CMainFrame::OnFont2)						// 궁서
	ON_UPDATE_COMMAND_UI(ID_font2, &CMainFrame::OnUpdateFont2)		// text type .e

	// bg
	ON_COMMAND(ID_B_COLOR, &CMainFrame::OnBColor)						// bg color .s
	ON_UPDATE_COMMAND_UI(ID_B_COLOR, &CMainFrame::OnUpdateBColor)
	ON_COMMAND(ID_B_BLACK, &CMainFrame::OnBBlack)						
	ON_UPDATE_COMMAND_UI(ID_B_BLACK, &CMainFrame::OnUpdateBBlack)
	ON_COMMAND(ID_B_RED, &CMainFrame::OnBRed)
	ON_UPDATE_COMMAND_UI(ID_B_RED, &CMainFrame::OnUpdateBRed)
	ON_COMMAND(ID_B_GREEN, &CMainFrame::OnBGreen)
	ON_UPDATE_COMMAND_UI(ID_B_GREEN, &CMainFrame::OnUpdateBGreen)
	ON_COMMAND(ID_B_BLUE, &CMainFrame::OnBBlue)
	ON_UPDATE_COMMAND_UI(ID_B_BLUE, &CMainFrame::OnUpdateBBlue)
	ON_COMMAND(ID_B_WHITE, &CMainFrame::OnBWhite)
	ON_UPDATE_COMMAND_UI(ID_B_WHITE, &CMainFrame::OnUpdateBWhite)		// bg color .e
	
	// group
	ON_COMMAND(ID_EN_GROUP, &CMainFrame::OnEnGroup)							// groups	.s
	ON_UPDATE_COMMAND_UI(ID_EN_GROUP, &CMainFrame::OnUpdateEnGroup)
	ON_COMMAND(ID_DE_GROUP, &CMainFrame::OnDeGroup)	
	ON_UPDATE_COMMAND_UI(ID_DE_GROUP, &CMainFrame::OnUpdateDeGroup)			// groups	.e

	END_MESSAGE_MAP()
// PS : clipboard 랑 group 빼고 해주세요
// PS2: marker 는 안건들여도 되고, brush style 은 0 := solid, 1 := hatch 2 := Null 로 상수 처리하고
// PS3: 나머지 pen style 같은거는 PS_SOLID 같은 정의된 상수로 해주시고
// PS4: font style 같이 동시에 가능한 처리는 & 연산을 이용하면 됩니다.

// clipboard
void CMainFrame::OnEditCut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMainFrame::OnUpdateEditCut(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnEditCopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMainFrame::OnUpdateEditCopy(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnEditPaste()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMainFrame::OnUpdateEditPaste(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}

// tools
void CMainFrame::OnMouse()		// selector
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 0;}
void CMainFrame::OnUpdateMouse(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 0);}
void CMainFrame::OnLine()		// Line
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 1;}
void CMainFrame::OnUpdateLine(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 1);}
void CMainFrame::OnPolyline()	// PolyLine
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 2;}
void CMainFrame::OnUpdatePolyline(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 2);}
void CMainFrame::OnCircle()		// ellipse
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 3;}
void CMainFrame::OnUpdateCircle(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 3);}
void CMainFrame::OnRectangle()	// rectangle
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 4;}
void CMainFrame::OnUpdateRectangle(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 4);}
void CMainFrame::OnText()		// text
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	CScroll* pView = (CScroll*) GetActiveView();
	pView->pointNumber = 0; pDoc->MMFlag = 0; pDoc->DrawingFlag = 0;	// drawing cancel
	pDoc->toolState = 5;}
void CMainFrame::OnUpdateText(CCmdUI *pCmdUI){	
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->toolState == 5);}

// line color
void CMainFrame::OnLineColor(){}	// marker
void CMainFrame::OnUpdateLineColor(CCmdUI *pCmdUI){	pCmdUI->SetCheck(0);}
void CMainFrame::OnLineBlack()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineColor = RGB(0, 0, 0);
	pDoc->toolState = 0;}
void CMainFrame::OnUpdateLineBlack(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineColor == RGB(0, 0, 0));}
void CMainFrame::OnLineRed()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineColor = RGB(255, 0, 0);}
void CMainFrame::OnUpdateLineRed(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineColor == RGB(255, 0, 0));}
void CMainFrame::OnLineGreen()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineColor = RGB(0, 255, 0);}
void CMainFrame::OnUpdateLineGreen(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineColor == RGB(0, 255, 0));}
void CMainFrame::OnLineBlue()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineColor = RGB(0, 0, 255);}
void CMainFrame::OnUpdateLineBlue(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineColor == RGB(0, 0, 255));}
void CMainFrame::OnLineWhite()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineColor = RGB(255, 255, 255);}
void CMainFrame::OnUpdateLineWhite(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineColor == RGB(255, 255, 255));}

// line style
void CMainFrame::OnLineSolid()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineStyle = PS_SOLID;}
void CMainFrame::OnUpdateLineSolid(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineStyle == PS_SOLID);}
void CMainFrame::OnLineDash()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineStyle = PS_DASH;}
void CMainFrame::OnUpdateLineDash(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineStyle == PS_DASH);}
void CMainFrame::OnLineNull()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineStyle = PS_NULL;}
void CMainFrame::OnUpdateLineNull(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineStyle == PS_NULL);}

// line Sz
void CMainFrame::OnLineThin()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineSz = 1;}
void CMainFrame::OnUpdateLineThin(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineSz == 1);}
void CMainFrame::OnLineNormal()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineSz = 2;}
void CMainFrame::OnUpdateLineNormal(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineSz == 2);}
void CMainFrame::OnLineThick()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->lineSz = 3;}
void CMainFrame::OnUpdateLineThick(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->lineSz == 3);}

// brush color
void CMainFrame::OnFaceColor(){}	// marker
void CMainFrame::OnUpdateFaceColor(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnFaceBlack()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushColor = RGB(0, 0, 0);}
void CMainFrame::OnUpdateFaceBlack(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushColor == RGB(0, 0, 0));}
void CMainFrame::OnFaceRed()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushColor = RGB(255, 0, 0);}
void CMainFrame::OnUpdateFaceRed(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushColor == RGB(255, 0, 0));}
void CMainFrame::OnFaceGreen()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushColor = RGB(0, 255, 0);}
void CMainFrame::OnUpdateFaceGreen(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushColor == RGB(0, 255, 0));}
void CMainFrame::OnFaceBlue()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushColor = RGB(0, 0, 255);}
void CMainFrame::OnUpdateFaceBlue(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushColor == RGB(0, 0, 255));}
void CMainFrame::OnFaceWhite()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushColor = RGB(255, 255, 255);}
void CMainFrame::OnUpdateFaceWhite(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushColor == RGB(255, 255, 255));}

// brush style
void CMainFrame::OnSolid()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushStyle = 0;}
void CMainFrame::OnUpdateSolid(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushStyle == 0);}
void CMainFrame::OnHatch()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushStyle = 1;}
void CMainFrame::OnUpdateHatch(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushStyle == 1);}
void CMainFrame::OnNull()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->brushStyle = 2;}
void CMainFrame::OnUpdateNull(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->brushStyle == 2);}

// text color
void CMainFrame::OnTextColor(){}	// marker
void CMainFrame::OnUpdateTextColor(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnTextBlack()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textColor = RGB(0, 0, 0);}
void CMainFrame::OnUpdateTextBlack(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textColor == RGB(0, 0, 0));}
void CMainFrame::OnTextRed()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textColor = RGB(255, 0, 0);}
void CMainFrame::OnUpdateTextRed(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textColor == RGB(255, 0, 0));}
void CMainFrame::OnTextGreen()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textColor = RGB(0, 255, 0);}
void CMainFrame::OnUpdateTextGreen(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textColor == RGB(0, 255, 0));}
void CMainFrame::OnTextBlue()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textColor = RGB(0, 0, 255);}
void CMainFrame::OnUpdateTextBlue(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textColor == RGB(0, 0, 255));}
void CMainFrame::OnTextWhite()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textColor = RGB(255, 255, 255);}
void CMainFrame::OnUpdateTextWhite(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textColor == RGB(255, 255, 255));}

// text bg color
void CMainFrame::OnTextBColor(){}	// marker
void CMainFrame::OnUpdateTextBColor(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnTextBBlack()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 0;
	pDoc->textBgColor = RGB(0, 0, 0);}	
void CMainFrame::OnUpdateTextBBlack(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 0 && pDoc->textBgColor == RGB(0, 0, 0));}
void CMainFrame::OnTextBRed()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 0;
	pDoc->textBgColor = RGB(255, 0, 0);}
void CMainFrame::OnUpdateTextBRed(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 0 && pDoc->textBgColor == RGB(255, 0, 0));}
void CMainFrame::OnTextBGreen()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 0;
	pDoc->textBgColor = RGB(0, 255, 0);}
void CMainFrame::OnUpdateTextBGreen(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 0 && pDoc->textBgColor == RGB(0, 255, 0));}
void CMainFrame::OnTextBBlue()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 0;
	pDoc->textBgColor = RGB(0, 0, 255);}
void CMainFrame::OnUpdateTextBBlue(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 0 && pDoc->textBgColor == RGB(0, 0, 255));}
void CMainFrame::OnTextBWhite()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 0;
	pDoc->textBgColor = RGB(255, 255, 255);}
void CMainFrame::OnUpdateTextBWhite(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 0 && pDoc->textBgColor == RGB(255, 255, 255));}
void CMainFrame::OnTextbgnull()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textBgFlag = 1;}
void CMainFrame::OnUpdateTextbgnull(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textBgFlag == 1);}

// text style
void CMainFrame::OnTextThick()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();//MessageBox(_T("ASD"), _T("A"));
	pDoc->textWeight = 900;}//FW_HEAVY;}
void CMainFrame::OnUpdateTextThick(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck( (pDoc->textWeight) == (byte)900);}//FW_HEAVY);}
void CMainFrame::OnTextUnderline()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textUnderLine = 1;}
void CMainFrame::OnUpdateTextUnderline(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textUnderLine == 1);}
void CMainFrame::OnTextTilt()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textItalic = 1;}
void CMainFrame::OnUpdateTextTilt(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textItalic == 1);}
void CMainFrame::OnTInit()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textWeight = 400;	pDoc->textItalic = pDoc->textUnderLine = 0;	
}


// text sz
void CMainFrame::OnT8()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textSz = 15;}
void CMainFrame::OnUpdateT8(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textSz == 15);}
void CMainFrame::OnT10()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textSz = 20;}
void CMainFrame::OnUpdateT10(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textSz == 20);}
void CMainFrame::OnT12()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textSz = 25;}
void CMainFrame::OnUpdateT12(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textSz == 25);}

// font type
void CMainFrame::OnFont1()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textType = 0;}
void CMainFrame::OnUpdateFont1(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textType == 0);}
void CMainFrame::OnFont2()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->textType = 1;}
void CMainFrame::OnUpdateFont2(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->textType == 1);}

// background color
void CMainFrame::OnBColor(){}	// marker
void CMainFrame::OnUpdateBColor(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnBBlack()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->bgColor = RGB(0, 0, 0); Invalidate();}
void CMainFrame::OnUpdateBBlack(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->bgColor == RGB(0, 0, 0));}
void CMainFrame::OnBRed()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->bgColor = RGB(255, 0, 0); Invalidate();}
void CMainFrame::OnUpdateBRed(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->bgColor == RGB(255, 0, 0));}
void CMainFrame::OnBGreen()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->bgColor = RGB(0, 255, 0); Invalidate();}
void CMainFrame::OnUpdateBGreen(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->bgColor == RGB(0, 255, 0));}
void CMainFrame::OnBBlue()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->bgColor = RGB(0, 0, 255); Invalidate();}
void CMainFrame::OnUpdateBBlue(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->bgColor == RGB(0, 0, 255));}
void CMainFrame::OnBWhite()
{	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pDoc->bgColor = RGB(255, 255, 255); Invalidate();}
void CMainFrame::OnUpdateBWhite(CCmdUI *pCmdUI){
	pCmdUI->Enable(TRUE);
	CGraphic_editorDoc* pDoc = (CGraphic_editorDoc*) GetActiveDocument();
	pCmdUI->SetCheck(pDoc->bgColor == RGB(255, 255, 255));}

// group
void CMainFrame::OnEnGroup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMainFrame::OnUpdateEnGroup(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}
void CMainFrame::OnDeGroup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CMainFrame::OnUpdateDeGroup(CCmdUI *pCmdUI){	pCmdUI->Enable(TRUE);}