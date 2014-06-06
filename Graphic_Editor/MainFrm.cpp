
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "Graphic_editor.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_MOUSE, &CMainFrame::OnUpdateMouse)
	ON_UPDATE_COMMAND_UI(ID_POLYLINE, &CMainFrame::OnUpdatePolyline)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMainFrame::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_CIRCLE, &CMainFrame::OnUpdateCircle)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CMainFrame::OnUpdateRectangle)
	ON_UPDATE_COMMAND_UI(ID_TEXT, &CMainFrame::OnUpdateText)
	ON_UPDATE_COMMAND_UI(ID_LINE_BLACK, &CMainFrame::OnUpdateLineBlack)
	ON_UPDATE_COMMAND_UI(ID_LINE_BLUE, &CMainFrame::OnUpdateLineBlue)
	ON_UPDATE_COMMAND_UI(ID_LINE_GREEN, &CMainFrame::OnUpdateLineGreen)
	ON_UPDATE_COMMAND_UI(ID_LINE_RED, &CMainFrame::OnUpdateLineRed)
	ON_UPDATE_COMMAND_UI(ID_LINE_WHITE, &CMainFrame::OnUpdateLineWhite)
	ON_UPDATE_COMMAND_UI(ID_SOLID, &CMainFrame::OnUpdateSolid)
	ON_UPDATE_COMMAND_UI(ID_HATCH, &CMainFrame::OnUpdateHatch)
	ON_UPDATE_COMMAND_UI(ID_NULL, &CMainFrame::OnUpdateNull)
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLACK, &CMainFrame::OnUpdateTextBlack)
	ON_UPDATE_COMMAND_UI(ID_TEXT_BLUE, &CMainFrame::OnUpdateTextBlue)
	ON_UPDATE_COMMAND_UI(ID_TEXT_GREEN, &CMainFrame::OnUpdateTextGreen)
	ON_UPDATE_COMMAND_UI(ID_TEXT_WHITE, &CMainFrame::OnUpdateTextWhite)
	ON_UPDATE_COMMAND_UI(ID_TEXT_THICK, &CMainFrame::OnUpdateTextThick)
	ON_UPDATE_COMMAND_UI(ID_TEXT_UNDERLINE, &CMainFrame::OnUpdateTextUnderline)
	ON_UPDATE_COMMAND_UI(ID_TEXT_TILT, &CMainFrame::OnUpdateTextTilt)
	ON_UPDATE_COMMAND_UI(ID_EN_GROUP, &CMainFrame::OnUpdateEnGroup)
	ON_UPDATE_COMMAND_UI(ID_DE_GROUP, &CMainFrame::OnUpdateDeGroup)
	ON_UPDATE_COMMAND_UI(ID_FACE_BLACK, &CMainFrame::OnUpdateFaceBlack)
	ON_UPDATE_COMMAND_UI(ID_FACE_BLUE, &CMainFrame::OnUpdateFaceBlue)
	ON_UPDATE_COMMAND_UI(ID_FACE_GREEN, &CMainFrame::OnUpdateFaceGreen)
	ON_UPDATE_COMMAND_UI(ID_FACE_RED, &CMainFrame::OnUpdateFaceRed)
	ON_UPDATE_COMMAND_UI(ID_FACE_WHITE, &CMainFrame::OnUpdateFaceWhite)
	ON_UPDATE_COMMAND_UI(ID_TEXT_RED, &CMainFrame::OnUpdateTextRed)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndToolBar2.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar2.LoadToolBar(IDR_TOOLBAR2))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	m_wndToolBar2.SetButtonInfo(6,ID_LINE_POSITION,TBBS_SEPARATOR,90);
 
	CRect itemRect1; //콤보를넣을 사각형을 만든다 

	m_wndToolBar2.GetItemRect(6,&itemRect1);

	itemRect1.left+=5; //앞여백 
	itemRect1.right+=5; //뒤여백 
	itemRect1.bottom+=100; //콤보가열릴 공간확보 

	m_combo1.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,itemRect1,&m_wndToolBar2,ID_COMBO1); //콤보박스를 툴바에 붙여준다 

	m_combo1.AddString(_T("보통")); //내용추가
	m_combo1.AddString(_T("얇게")); //내용추가
	m_combo1.AddString(_T("굵게")); //내용추가
	m_combo1.SetCurSel(0); //셀 선택 

	if (!m_wndToolBar3.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar3.LoadToolBar(IDR_TOOLBAR3))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	m_wndToolBar3.SetButtonInfo(0,ID_LINE_POSITION,TBBS_SEPARATOR,70);
 
	CRect itemRect2; //콤보를넣을 사각형을 만든다 

	m_wndToolBar3.GetItemRect(0,&itemRect2);

	itemRect2.left+=5; //앞여백 
	itemRect2.right+=5; //뒤여백 
	itemRect2.bottom+=160; //콤보가열릴 공간확보

	m_combo2.Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,itemRect2,&m_wndToolBar3,ID_COMBO2); //콤보박스를 툴바에 붙여준다 

	m_combo2.AddString(_T("8")); //내용추가
	m_combo2.AddString(_T("10")); //내용추가
	m_combo2.AddString(_T("12")); //내용추가
	m_combo2.AddString(_T("14")); //내용추가
	m_combo2.AddString(_T("16")); //내용추가
	m_combo2.SetCurSel(0); //셀 선택 

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar2.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar3.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndToolBar2);
	DockControlBar(&m_wndToolBar3);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기


void CMainFrame::OnUpdateMouse(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdatePolyline(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLine(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateCircle(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateRectangle(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateText(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLineBlack(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLineBlue(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLineGreen(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLineRed(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateLineWhite(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateSolid(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateHatch(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateNull(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextBlack(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	
}

void CMainFrame::OnUpdateTextBlue(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextGreen(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextWhite(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextThick(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextUnderline(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextTilt(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateEnGroup(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateDeGroup(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateFaceBlack(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateFaceBlue(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateFaceGreen(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateFaceRed(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateFaceWhite(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}


void CMainFrame::OnUpdateTextRed(CCmdUI *pCmdUI)
{	pCmdUI->Enable(TRUE);	}
