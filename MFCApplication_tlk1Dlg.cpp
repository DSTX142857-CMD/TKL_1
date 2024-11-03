
// MFCApplication_tlk1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication_tlk1.h"
#include "MFCApplication_tlk1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<iostream>
using namespace std;
class BankCard
{
private:
	long CardNum;
	string CardName;
	long PassWord;
	string BankName;
public:
	//构造函数，用于初始化信息
	BankCard(long cardnum, string cardname, long password, string bankname);
	// 设置或修改卡号  
	void setCardNum(long cardnum) { CardNum = cardnum; }
	// 获取卡号  
	long getCardNum() { return CardNum; }
	// 设置或修改密码  
	void setPassword(long pwd) { PassWord = pwd; }
	// 获取密码  
	long getPassword() { return PassWord; }
	// 显示信息  
	void displayInfo() {
		cout << "Card Number: " << CardNum << endl;
		cout << "Holder Name: " << CardName << endl;
		cout << "Bank Name: " << BankName << endl;
	}
};
BankCard::BankCard(long cardnum, string cardname, long password, string bankname)
{
	CardNum = cardnum;
	CardName = cardname;
	PassWord = password;
	BankName = bankname;
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationtlk1Dlg 对话框



CMFCApplicationtlk1Dlg::CMFCApplicationtlk1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_TLK1_DIALOG, pParent)
	, m_yhkh(0)
	, m_mm(0)
	, m_xsxx(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationtlk1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_yhkh);
	DDX_Text(pDX, IDC_EDIT2, m_mm);
	DDX_Text(pDX, IDC_EDIT3, m_xsxx);
}

BEGIN_MESSAGE_MAP(CMFCApplicationtlk1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationtlk1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplicationtlk1Dlg 消息处理程序

BOOL CMFCApplicationtlk1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationtlk1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationtlk1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationtlk1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationtlk1Dlg::OnBnClickedButton1()
{
	BankCard yhk(00000000,"aaa",000000,"bbb");
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	long id = m_yhkh;
	long mm = m_mm;
	yhk.setCardNum(id);
	yhk.setPassword(mm);
	CString xs;
	xs = "登录成功";
	m_xsxx = xs;
	UpdateData(FALSE);
}
