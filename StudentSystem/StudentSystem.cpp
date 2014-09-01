#include "StudentSystem.h"
#include "System.h"

System Sys;

/*
* 由于本程序需要通过ODBC连接SQL Server数据库，请老师测试程序前确认是否安装好SQL Server。
* 如果装好了，请在ODBC数据源中创建系统DSN，数据库名为StudentSystem，账号为Lynn，密码为lml123456。
* 然后将源程序中StudentSystem.cpp文件中的19-27、33-39行取消注释，然后运行程序。
* 如果没有连接好SQL Server直接取消注释运行，将会直接报错。
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, "error!", _T("创建窗口"), NULL);
		return 1;
	}
	//retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	//if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
	//	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*) SQL_OV_ODBC3, 0);
	//	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
	//		retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	//		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
	//			SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER) 5, 0);
	//			retcode = SQLConnect(hdbc, (SQLCHAR*) "StudentSystem", SQL_NTS, (SQLCHAR*) "Lynn", SQL_NTS, (SQLCHAR*) "lml123456", SQL_NTS);
	//			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
					while (GetMessage(&msg, NULL, 0, 0))
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
	//				SQLDisconnect(hdbc);
	//			}
	//			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	//		}
	//	}
	//	SQLFreeHandle(SQL_HANDLE_ENV, henv);
	//}
	return (int) msg.wParam;
}

/**
* @brief       功能：用于同数据库的连接
* @param [in]  hwnd:hWnd
* @return      bool 以确认是否连接成功
* @exception
*/
BOOL OpenFileDialog(HWND hWnd){
	static TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("Text Files (*.TXT)\0*.txt\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName((LPOPENFILENAME) &ofn);
}

/**
* @brief       功能：用于建立消息循环
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LPCSTR output = "学生成绩管理系统";
	PAINTSTRUCT ps;
	HDC hDC;
	HFONT hF;

	switch (message)
	{
	case WM_CREATE:
		hMenu = GetMenu(hWnd);
		EnableMenuItem(hMenu, ID_40005, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40006, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40007, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40008, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40012, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40013, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40014, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40015, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40019, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40020, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40021, MF_GRAYED);
		EnableMenuItem(hMenu, ID_40022, MF_GRAYED);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_40001://管理员登录
			MessageBox(hWnd, "请输入管理员账号及密码\n账号和密码用逗号加一个空格隔开，如：\n3110102421, 123456\n账号长度不超过10位，密码长度不超过20位", "管理员登陆", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "登陆失败！", "管理员登陆", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.admin_login(pBuffer)){
				MessageBox(hWnd, "登陆成功！", "管理员登陆", MB_OK);
			EnableMenuItem(hMenu, ID_40005, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40006, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40007, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40008, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40012, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40013, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40014, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40015, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40019, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40020, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40021, MF_ENABLED);
			EnableMenuItem(hMenu, ID_40022, MF_ENABLED);
			}
			break;
		case ID_40003://本科生-成绩显示
			if (!Sys.Student_search_degree("B"))
				MessageBox(hWnd, "查询失败！", "成绩显示", MB_OK);
			break;
		case ID_40004://本科生-成绩查询
			MessageBox(hWnd, "请输入学生学号，如：\nXXXXXX\n学号长度不超过10位", "成绩查询", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "查询失败！", "本科生成绩查询", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "字符长度超过限制！查询失败！", "成绩查询", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "查询失败！", "成绩查询", MB_OK);
			break;
		case ID_40005://本科生-成绩修改
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "修改失败！", "本科生成绩修改", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "修改成功！", "成绩修改", MB_OK);
			break;
		case ID_40006://本科生-成绩删除
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "删除失败！", "本科生成绩删除", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "删除成功！", "成绩删除", MB_OK);
			break;
		case ID_40007://本科生-成绩录入-单个录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "本科生成绩单个录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "单个录入", MB_OK);
			break;
		case ID_40008://本科生-成绩录入-批量录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "本科生成绩批量录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "批量录入", MB_OK);
			break;
		case ID_40010://硕士生-成绩显示
			if (!Sys.Student_search_degree("M"))
				MessageBox(hWnd, "查询失败！", "成绩显示", MB_OK);
			break;
			break;
		case ID_40011://硕士生-成绩查询
			MessageBox(hWnd, "请输入学生学号，如：\nXXXXXX\n学号长度不超过10位", "成绩查询", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "查询失败！", "硕士生成绩查询", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer; 
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "字符长度超过限制！查询失败！", "成绩查询", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "查询失败！", "成绩查询", MB_OK);
			break;
		case ID_40012://硕士生-成绩修改
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "修改失败！", "硕士生成绩修改", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "修改成功！", "成绩修改", MB_OK);
			break;
		case ID_40013://硕士生-成绩删除
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "删除失败！", "硕士生成绩删除", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "删除成功！", "成绩删除", MB_OK);
			break;
		case ID_40014://硕士生-成绩录入-单个录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "硕士生成绩单个录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "单个录入", MB_OK);
			break;
		case ID_40015://硕士生-成绩录入-批量录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "硕士生成绩批量录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "批量录入", MB_OK);
			break;
		case ID_40017://博士生-成绩显示
			if (!Sys.Student_search_degree("P"))
				MessageBox(hWnd, "查询失败！", "成绩显示", MB_OK);
			break;
		case ID_40018://博士生-成绩查询
			MessageBox(hWnd, "请输入学生学号，如：\nXXXXXX\n学号长度不超过10位", "成绩查询", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "查询失败！", "博士生成绩查询", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "字符长度超过限制！查询失败！", "成绩查询", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "查询失败！", "成绩查询", MB_OK);
			break;
		case ID_40019://博士生-成绩修改
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "修改失败！", "博士生成绩修改", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "修改成功！", "成绩修改", MB_OK);
			break;
		case ID_40020://博士生-成绩删除
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "删除失败！", "博士生成绩删除", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "删除成功！", "成绩删除", MB_OK);
			break;
		case ID_40021://博士生-成绩录入-单个录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "博士生成绩单个录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "单个录入", MB_OK);
			break;
		case ID_40022://博士生-成绩录入-批量录入
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "录入失败！", "博士生成绩批量录入", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "录入成功！", "批量录入", MB_OK);
			break;
		default:
			break;
		}
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hF = CreateFont(100, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "黑体");
		SelectObject(hDC, hF);
		TextOut(hDC, 200, 220, output, 16);
		DeleteObject(hF);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

/**
* @brief       功能：用于创建窗口
*/
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow){
	WNDCLASSEX wcex;
	TCHAR szWindowClass[] = "学生成绩管理系统";
	TCHAR szTitle[] = "学生成绩管理系统";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = (LPCSTR) IDR_MENU1;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex))
		return FALSE;
	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}