
// MFCApplication_tlk1Dlg.h: 头文件
//

#pragma once


// CMFCApplicationtlk1Dlg 对话框
class CMFCApplicationtlk1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplicationtlk1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_TLK1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	long m_yhkh;
	long m_mm;
	CString m_xsxx;
	afx_msg void OnBnClickedButton1();
};
