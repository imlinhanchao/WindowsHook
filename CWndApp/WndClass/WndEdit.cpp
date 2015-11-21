#include "StdAfx.h"
#include "WndEdit.h"

CWndEdit::CWndEdit(void)
{
}

CWndEdit::~CWndEdit(void)
{
}

void CWndEdit::PasteTo(TCHAR* szText)
{
	CWndTool::CopytoTheClipboard(CString(szText), m_hWnd);
	((CEdit*)GetWindow())->Paste();
}

bool CWndEdit::ReadOnly(bool bReadOnly)
{
	return ((CEdit*)GetWindow())->SetReadOnly(bReadOnly ? TRUE :FALSE) == TRUE;
}

bool CWndEdit::GetText(TCHAR* szText, int& nMaxLen)
{
	LONG dwStyle = GetWindowLong(m_hWnd, GWL_STYLE);			// 获取编辑框原来样式
	SetWindowWord(m_hWnd, GWL_STYLE, 0);						// 取消所有样式
	SetWindowLong(m_hWnd, GWL_STYLE, dwStyle & ~ES_PASSWORD);	// 去掉密码属性(如果有的话)
	bool bSuccess = CWndBase::GetText(szText, nMaxLen);
	SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);					//还原编辑框原来样式
	return bSuccess;
}
