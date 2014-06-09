
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CToolBar          m_wndToolBar;
	CToolBar          m_wndToolBar2;
	CToolBar          m_wndToolBar3;
	CStatusBar        m_wndStatusBar;
	CComboBox		   m_combo1;
	CComboBox		   m_combo2;
	CBitmap		   m_bitmap;
	CImageList	   imageList;
												
// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg void OnSelectCombo();
	afx_msg void OnMouse();
	afx_msg void OnUpdateMouse(CCmdUI *pCmdUI);
	afx_msg void OnLine();
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnPolyline();
	afx_msg void OnUpdatePolyline(CCmdUI *pCmdUI);
	afx_msg void OnRectangle();
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnCircle();
	afx_msg void OnUpdateCircle(CCmdUI *pCmdUI);
	afx_msg void OnLineBlack();
	afx_msg void OnUpdateLineBlack(CCmdUI *pCmdUI);
	afx_msg void OnLineRed();
	afx_msg void OnUpdateLineRed(CCmdUI *pCmdUI);
	afx_msg void OnLineGreen();
	afx_msg void OnUpdateLineGreen(CCmdUI *pCmdUI);
	afx_msg void OnLineBlue();
	afx_msg void OnUpdateLineBlue(CCmdUI *pCmdUI);
	afx_msg void OnLineWhite();
	afx_msg void OnUpdateLineWhite(CCmdUI *pCmdUI);
	afx_msg void OnLineSolid();
	afx_msg void OnUpdateLineSolid(CCmdUI *pCmdUI);
	afx_msg void OnLineDash();
	afx_msg void OnUpdateLineDash(CCmdUI *pCmdUI);
	afx_msg void OnLineNull();
	afx_msg void OnUpdateLineNull(CCmdUI *pCmdUI);
	afx_msg void OnSolid();
	afx_msg void OnUpdateSolid(CCmdUI *pCmdUI);
	afx_msg void OnHatch();
	afx_msg void OnUpdateHatch(CCmdUI *pCmdUI);
	afx_msg void OnNull();
	afx_msg void OnUpdateNull(CCmdUI *pCmdUI);
	afx_msg void OnFaceBlack();
	afx_msg void OnUpdateFaceBlack(CCmdUI *pCmdUI);
	afx_msg void OnFaceRed();
	afx_msg void OnUpdateFaceRed(CCmdUI *pCmdUI);
	afx_msg void OnFaceGreen();
	afx_msg void OnUpdateFaceGreen(CCmdUI *pCmdUI);
	afx_msg void OnFaceBlue();
	afx_msg void OnUpdateFaceBlue(CCmdUI *pCmdUI);
	afx_msg void OnFaceWhite();
	afx_msg void OnUpdateFaceWhite(CCmdUI *pCmdUI);
	afx_msg void OnTextBlack();
	afx_msg void OnUpdateTextBlack(CCmdUI *pCmdUI);
	afx_msg void OnTextRed();
	afx_msg void OnUpdateTextRed(CCmdUI *pCmdUI);
	afx_msg void OnTextGreen();
	afx_msg void OnUpdateTextGreen(CCmdUI *pCmdUI);
	afx_msg void OnTextBlue();
	afx_msg void OnUpdateTextBlue(CCmdUI *pCmdUI);
	afx_msg void OnTextWhite();
	afx_msg void OnUpdateTextWhite(CCmdUI *pCmdUI);
	afx_msg void OnTextBBlack();
	afx_msg void OnUpdateTextBBlack(CCmdUI *pCmdUI);
	afx_msg void OnTextBRed();
	afx_msg void OnUpdateTextBRed(CCmdUI *pCmdUI);
	afx_msg void OnTextBGreen();
	afx_msg void OnUpdateTextBGreen(CCmdUI *pCmdUI);
	afx_msg void OnTextBBlue();
	afx_msg void OnUpdateTextBBlue(CCmdUI *pCmdUI);
	afx_msg void OnTextBWhite();
	afx_msg void OnUpdateTextBWhite(CCmdUI *pCmdUI);
	afx_msg void OnTextThick();
	afx_msg void OnUpdateTextThick(CCmdUI *pCmdUI);
	afx_msg void OnTextUnderline();
	afx_msg void OnUpdateTextUnderline(CCmdUI *pCmdUI);
	afx_msg void OnTextTilt();
	afx_msg void OnUpdateTextTilt(CCmdUI *pCmdUI);
	afx_msg void OnEnGroup();
	afx_msg void OnUpdateEnGroup(CCmdUI *pCmdUI);
	afx_msg void OnDeGroup();
	afx_msg void OnUpdateDeGroup(CCmdUI *pCmdUI);
	afx_msg void OnBBlack();
	afx_msg void OnUpdateBBlack(CCmdUI *pCmdUI);
	afx_msg void OnBRed();
	afx_msg void OnUpdateBRed(CCmdUI *pCmdUI);
	afx_msg void OnBGreen();
	afx_msg void OnUpdateBGreen(CCmdUI *pCmdUI);
	afx_msg void OnBBlue();
	afx_msg void OnUpdateBBlue(CCmdUI *pCmdUI);
	afx_msg void OnBWhite();
	afx_msg void OnUpdateBWhite(CCmdUI *pCmdUI);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLineThin();
	afx_msg void OnUpdateLineThin(CCmdUI *pCmdUI);
	afx_msg void OnLineNormal();
	afx_msg void OnUpdateLineNormal(CCmdUI *pCmdUI);
	afx_msg void OnLineThick();
	afx_msg void OnUpdateLineThick(CCmdUI *pCmdUI);
	afx_msg void OnLineColor();
	afx_msg void OnUpdateLineColor(CCmdUI *pCmdUI);
	afx_msg void OnFaceColor();
	afx_msg void OnUpdateFaceColor(CCmdUI *pCmdUI);
	afx_msg void OnTextColor();
	afx_msg void OnUpdateTextColor(CCmdUI *pCmdUI);
	afx_msg void OnTextBColor();
	afx_msg void OnUpdateTextBColor(CCmdUI *pCmdUI);
	afx_msg void OnBColor();
	afx_msg void OnUpdateBColor(CCmdUI *pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditCut(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditCopy(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
	afx_msg void OnText();
	afx_msg void OnUpdateText(CCmdUI *pCmdUI);
	afx_msg void OnT8();
	afx_msg void OnUpdateT8(CCmdUI *pCmdUI);
	afx_msg void OnT10();
	afx_msg void OnUpdateT10(CCmdUI *pCmdUI);
	afx_msg void OnT12();
	afx_msg void OnUpdateT12(CCmdUI *pCmdUI);
	afx_msg void OnFont1();
	afx_msg void OnUpdateFont1(CCmdUI *pCmdUI);
	afx_msg void OnFont2();
	afx_msg void OnUpdateFont2(CCmdUI *pCmdUI);
	afx_msg void OnTextbgnull();
	afx_msg void OnUpdateTextbgnull(CCmdUI *pCmdUI);
	afx_msg void OnTInit();
};


