
// BtnLoadDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "BtnLoad.h"
#include "BtnLoadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CBtnLoadDlg 대화 상자



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


// CBtnLoadDlg 메시지 처리기

BOOL CBtnLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBtnLoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBtnLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBtnLoadDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


		
		// 가장 최근 줄에 focus가 가도록 한다. (왜 잘 동작안할까..)
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
		// 에디트 박스에 있는 것을 저장한다. 
		UpdateData(TRUE);
		file.WriteString(m_strStatus);
		// 종료한다. 
		file.Close();
	}
}


void CBtnLoadDlg::OnIdclose()
{
	
}




