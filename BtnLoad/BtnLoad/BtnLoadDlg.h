
// BtnLoadDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CBtnLoadDlg ��ȭ ����
class CBtnLoadDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CBtnLoadDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BTNLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnLoad();
	// �߰� ������ 
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
