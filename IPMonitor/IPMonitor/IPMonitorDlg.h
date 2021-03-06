
// IPMonitorDlg.h : header file
//

#pragma once
#include "NIC.h"
#include "Device.h"
#include "IP.h"
#include "EthernetFrame.h"

#define WM_RECV (WM_USER + 100)

// CIPMonitorDlg dialog
class CIPMonitorDlg : public CDialog
{
// Construction
public:
	CIPMonitorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IPMONITOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRecv(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonAbout();
	afx_msg void OnCbnSelchangeComboNic();
	afx_msg void OnBnClickedButtonScan();
	afx_msg void OnBnClickedCheckSource();
	afx_msg void OnBnClickedCheckDestination();
	static UINT recvAll(LPVOID lpParam);
public:
	NIC nic;
	int index;
	Device device;
	bool started;
	CWinThread *hThreadrecv;
	int srcchecked;
	int dstchecked;
	int flag;
	DWORD localip;
	DWORD srcip;
	DWORD dstip;
	BYTE proto;

	CComboBox m_CComboBox;
	CListCtrl m_CListCtrl;
	CButton m_CheckBoxSource;
	CButton m_CheckBoxDestination;
	CString m_edit_ipaddress;
	CString m_edit_subnetmask;
	CString m_edit_macaddress;
	CString m_edit_gatewayipaddress;
	CString m_edit_gatewaymac;
};
