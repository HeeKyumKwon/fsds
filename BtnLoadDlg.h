
// BtnLoadDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CBtnLoadDlg 대화 상자
class CBtnLoadDlg : public CDialogEx
{
// 생성입니다.
public:
	CBtnLoadDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BTNLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnLoad();
	// 추가 변수들 
	// Folder path
	CString m_strPath;
	CString m_strFolderPath;
	CString m_strStatus;
	// File
	FILE *ifp;
	afx_msg void OnIdclose();
	afx_msg void OnClose();
	int **data;
	CEdit m_ctrlStatus;
	afx_msg void OnBnClickedBtnSave();
};
