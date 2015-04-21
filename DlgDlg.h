// DlgDlg.h : header file
//

#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog
// added s
#include "Figure.h"
#include "afxwin.h"
#include "stackm.cpp"
#include "undoredo.cpp"
using namespace std;
// added e
class CDlgDlg : public CDialog
{
	//!!2
	enum FIGURES{RECTANGLE,SQUARE,ELLIPSE,CIRCLE,TRIANGLE,LINE,PEN,ARROW};
	enum MODE{SHAPE,DEL,PAINT,PICK};
	FIGURES futureFigKIND;
	MODE mode;
    //!!8
    COLORREF curColor;
	CBrush myBrush;

	// added s
	Figure *f;
	//!!6 b
	//vector <Figure *> figs;
	CTypedPtrArray< CObArray, Figure*> figs;
	//!!6 e
	UndoRedo<Figure*> UR;
	Figure* Temp;
	bool isPressed;
	CPoint startP;
	CPoint endP;
	// added e
	// Construction
public:
	CDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDlg)
	enum { IDD = IDD_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	BOOL isThin;
	afx_msg void OnBnClickedCheck1();
	CButton mbExit;
	CButton mbSave;
	CButton mbLoad;
	CButton mbRect;
	CButton mbSqua;
	CButton mbElip;
	CButton mbCirc;
	CButton mbLine;
	CButton mbPen;
	CButton mbTri;
	CButton mbDel;
	CButton mbPick;
	CButton mbPaint;
	CButton mbArrow;
	CButton mbUndo;
	CButton mbRedo;
	CButton mbCls;
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
