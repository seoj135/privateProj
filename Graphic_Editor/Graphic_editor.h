
// Graphic_editor.h : Graphic_editor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CGraphic_editorApp:
// �� Ŭ������ ������ ���ؼ��� Graphic_editor.cpp�� �����Ͻʽÿ�.
//

class CGraphic_editorApp : public CWinApp
{
public:
	CGraphic_editorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGraphic_editorApp theApp;
