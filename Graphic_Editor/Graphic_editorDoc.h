
// Graphic_editorDoc.h : CGraphic_editorDoc 클래스의 인터페이스
//


#pragma once
#include "graphic.h"

class CGraphic_editorDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CGraphic_editorDoc();
	DECLARE_DYNCREATE(CGraphic_editorDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CGraphic_editorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

	// selector
public:
	int OIA[200];	// Object index Array
	int OIAC;
	int GIA[200];	// Groups index Array
	int GIAC;
	// .. data
public:
	graphic obj[200];
	int objC;
	Groups grp[200];
	int grpC;

	int DrawingFlag;
	int MMFlag;		// mouse move flag 0, 1
	int LbttnFlag;	// 0 := not down, 1 := now down
	int toolState;	// 0 := selector
					// 1 := line,	2 := polyline, 3 := ellipse,
					// 4 := rectangle,		5 := text
	COLORREF penColor, brushColor, bgColor;
	int penSz, penStyle;
	int brushStyle;	// solid or hatch
	// method
	int addObj(int index);
};
