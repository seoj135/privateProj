
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CToolBar          m_wndToolBar;
	CToolBar          m_wndToolBar2;
	CToolBar          m_wndToolBar3;
	CStatusBar        m_wndStatusBar;
	CComboBox		   m_combo1;
	CComboBox		   m_combo2;
												
// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnUpdateMouse(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePolyline(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateText(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLineBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLineBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLineGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLineRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLineWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHatch(CCmdUI *pCmdUI);
	afx_msg void OnUpdateNull(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextThick(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextUnderline(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextTilt(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEnGroup(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDeGroup(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFaceBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFaceBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFaceGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFaceRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFaceWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextRed(CCmdUI *pCmdUI);
};


