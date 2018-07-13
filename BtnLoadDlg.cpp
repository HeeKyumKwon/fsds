
// BtnLoadDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "BtnLoad.h"
#include "BtnLoadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBtnLoadDlg ��ȭ ����



CBtnLoadDlg::CBtnLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBtnLoadDlg::IDD, pParent)
	, m_strStatus(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBtnLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSOLE, m_strStatus);
	DDX_Control(pDX, IDC_EDIT_CONSOLE, m_ctrlStatus);
}

BEGIN_MESSAGE_MAP(CBtnLoadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBtnLoadDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_BTN_LOAD, &CBtnLoadDlg::OnBnClickedBtnLoad)
	ON_COMMAND(IDCLOSE, &CBtnLoadDlg::OnIdclose)
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_BTN_SAVE, &CBtnLoadDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// CBtnLoadDlg �޽��� ó����

BOOL CBtnLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CBtnLoadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CBtnLoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CBtnLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBtnLoadDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}
void CBtnLoadDlg::OnClose()
{
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}


void CBtnLoadDlg::OnBnClickedBtnLoad()
{
	printf("[OnBnClickedBtnOpen] \n");
	CStdioFile ftxt;
	CFileException kEx;
	CFileDialog dlg(TRUE, _T("*.csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files(*.csv)|*.csv|"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		// Get file name 
		m_strPath = dlg.GetPathName();
		char charPtr[500];
		sprintf(charPtr, "%S", m_strPath);
		CString file_name = dlg.GetFileName();
		CString m_strStatus_temp;
		
		m_strStatus += "File name: ";
		m_strStatus += file_name;
		m_strStatus += "\r\n";

		// Set path to load 
		m_strStatus += "File path: ";
		m_strStatus += m_strPath;
		m_strStatus += "\r\n";
		ifp = fopen(charPtr, "r");
		
		// Save folder path for further saving 
		m_strFolderPath = m_strPath.Left(m_strPath.GetLength() - file_name.GetLength());
		m_strStatus += "Folder path: ";
		m_strStatus += m_strFolderPath;
		m_strStatus += "\r\n";

		// Load file using ifp
		// 1. Count number of items
		int nr_data = 0; 
		for (int i = 0;; i++){
			int doc_idx, word_idx, nr_word;
			if (fscanf(ifp, "%d,%d,%d", &doc_idx, &word_idx, &nr_word) == EOF)
				break;
			// count number of items
			nr_data++;
		}
		CString strTemp; strTemp.Format(L"nr_data: %d \r\n", nr_data);
		m_strStatus += strTemp;

		// 2. Allocate memory & Load
		rewind(ifp);
		data = (int**)malloc(nr_data*sizeof(int*));
		for (int i = 0; i < nr_data; i++) {
			data[i] = (int*)malloc(3 * sizeof(int));
			if (fscanf(ifp, "%d,%d,%d", &data[i][0], &data[i][1], &data[i][2]) == EOF)
				break;
			else
			{
				printf("%d: %d / %d / %d \n", i, data[i][0], data[i][1], data[i][2]);
			}
		}

		// 3. Show data loaded 
		for (int i = 0; i < nr_data; i++)
		{
			CString strTemp; strTemp.Format(L"[%d/%d] / %d %d %d \r\n"
				, i + 1, nr_data, data[i][0], data[i][1], data[i][2]);
			m_strStatus += strTemp;
		}


		
		// ���� �ֱ� �ٿ� focus�� ������ �Ѵ�. (�� �� ���۾��ұ�..)
		int str_len = m_ctrlStatus.GetLineCount();
		m_ctrlStatus.LineScroll(str_len);
		// Update text
		UpdateData(FALSE);

	}
}

void CBtnLoadDlg::OnBnClickedBtnSave()
{
	printf("[OnBnClickedBtnSave] \n");
	CString m_strPath;
	CStdioFile file;
	// CFile file;
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT Files(*.txt)|*.txt|"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		if (m_strPath.Right(4) != ".txt")
		{
			m_strPath += ".txt";
		}
		file.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);
		// ����Ʈ �ڽ��� �ִ� ���� �����Ѵ�. 
		UpdateData(TRUE);
		file.WriteString(m_strStatus);
		// �����Ѵ�. 
		file.Close();
	}
}


void CBtnLoadDlg::OnIdclose()
{
	
}




