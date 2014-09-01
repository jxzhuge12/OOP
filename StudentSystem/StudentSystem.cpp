#include "StudentSystem.h"
#include "System.h"

System Sys;

/*
* ���ڱ�������Ҫͨ��ODBC����SQL Server���ݿ⣬����ʦ���Գ���ǰȷ���Ƿ�װ��SQL Server��
* ���װ���ˣ�����ODBC����Դ�д���ϵͳDSN�����ݿ���ΪStudentSystem���˺�ΪLynn������Ϊlml123456��
* Ȼ��Դ������StudentSystem.cpp�ļ��е�19-27��33-39��ȡ��ע�ͣ�Ȼ�����г���
* ���û�����Ӻ�SQL Serverֱ��ȡ��ע�����У�����ֱ�ӱ���
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, "error!", _T("��������"), NULL);
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
* @brief       ���ܣ�����ͬ���ݿ������
* @param [in]  hwnd:hWnd
* @return      bool ��ȷ���Ƿ����ӳɹ�
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
* @brief       ���ܣ����ڽ�����Ϣѭ��
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LPCSTR output = "ѧ���ɼ�����ϵͳ";
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
		case ID_40001://����Ա��¼
			MessageBox(hWnd, "���������Ա�˺ż�����\n�˺ź������ö��ż�һ���ո�������磺\n3110102421, 123456\n�˺ų��Ȳ�����10λ�����볤�Ȳ�����20λ", "����Ա��½", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "��½ʧ�ܣ�", "����Ա��½", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.admin_login(pBuffer)){
				MessageBox(hWnd, "��½�ɹ���", "����Ա��½", MB_OK);
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
		case ID_40003://������-�ɼ���ʾ
			if (!Sys.Student_search_degree("B"))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ʾ", MB_OK);
			break;
		case ID_40004://������-�ɼ���ѯ
			MessageBox(hWnd, "������ѧ��ѧ�ţ��磺\nXXXXXX\nѧ�ų��Ȳ�����10λ", "�ɼ���ѯ", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�������ɼ���ѯ", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "�ַ����ȳ������ƣ���ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			break;
		case ID_40005://������-�ɼ��޸�
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "�޸�ʧ�ܣ�", "�������ɼ��޸�", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "�޸ĳɹ���", "�ɼ��޸�", MB_OK);
			break;
		case ID_40006://������-�ɼ�ɾ��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "ɾ��ʧ�ܣ�", "�������ɼ�ɾ��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "ɾ���ɹ���", "�ɼ�ɾ��", MB_OK);
			break;
		case ID_40007://������-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "�������ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		case ID_40008://������-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "�������ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		case ID_40010://˶ʿ��-�ɼ���ʾ
			if (!Sys.Student_search_degree("M"))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ʾ", MB_OK);
			break;
			break;
		case ID_40011://˶ʿ��-�ɼ���ѯ
			MessageBox(hWnd, "������ѧ��ѧ�ţ��磺\nXXXXXX\nѧ�ų��Ȳ�����10λ", "�ɼ���ѯ", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "��ѯʧ�ܣ�", "˶ʿ���ɼ���ѯ", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer; 
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "�ַ����ȳ������ƣ���ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			break;
		case ID_40012://˶ʿ��-�ɼ��޸�
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "�޸�ʧ�ܣ�", "˶ʿ���ɼ��޸�", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "�޸ĳɹ���", "�ɼ��޸�", MB_OK);
			break;
		case ID_40013://˶ʿ��-�ɼ�ɾ��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "ɾ��ʧ�ܣ�", "˶ʿ���ɼ�ɾ��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "ɾ���ɹ���", "�ɼ�ɾ��", MB_OK);
			break;
		case ID_40014://˶ʿ��-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "˶ʿ���ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		case ID_40015://˶ʿ��-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "˶ʿ���ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		case ID_40017://��ʿ��-�ɼ���ʾ
			if (!Sys.Student_search_degree("P"))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ʾ", MB_OK);
			break;
		case ID_40018://��ʿ��-�ɼ���ѯ
			MessageBox(hWnd, "������ѧ��ѧ�ţ��磺\nXXXXXX\nѧ�ų��Ȳ�����10λ", "�ɼ���ѯ", MB_OK);
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "��ѯʧ�ܣ�", "��ʿ���ɼ���ѯ", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (fileSize > 10)
				MessageBox(hWnd, "�ַ����ȳ������ƣ���ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			else if (!Sys.Student_search_stu(pBuffer))
				MessageBox(hWnd, "��ѯʧ�ܣ�", "�ɼ���ѯ", MB_OK);
			break;
		case ID_40019://��ʿ��-�ɼ��޸�
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "�޸�ʧ�ܣ�", "��ʿ���ɼ��޸�", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_re(pBuffer))
				MessageBox(hWnd, "�޸ĳɹ���", "�ɼ��޸�", MB_OK);
			break;
		case ID_40020://��ʿ��-�ɼ�ɾ��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "ɾ��ʧ�ܣ�", "��ʿ���ɼ�ɾ��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Sub_de(pBuffer))
				MessageBox(hWnd, "ɾ���ɹ���", "�ɼ�ɾ��", MB_OK);
			break;
		case ID_40021://��ʿ��-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "��ʿ���ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.One_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		case ID_40022://��ʿ��-�ɼ�¼��-����¼��
			if (OpenFileDialog(hWnd))
				hf = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			else
			{
				MessageBox(hWnd, "¼��ʧ�ܣ�", "��ʿ���ɼ�����¼��", MB_OK);
				break;
			}
			fileSize = GetFileSize(hf, NULL);
			tempBuffer = (char *) malloc(fileSize + 1);
			ReadFile(hf, tempBuffer, fileSize, &RSize, NULL);
			tempBuffer[fileSize] = '\0';
			pBuffer = tempBuffer;
			free(tempBuffer);
			if (Sys.Many_ent(pBuffer))
				MessageBox(hWnd, "¼��ɹ���", "����¼��", MB_OK);
			break;
		default:
			break;
		}
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hF = CreateFont(100, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "����");
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
* @brief       ���ܣ����ڴ�������
*/
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow){
	WNDCLASSEX wcex;
	TCHAR szWindowClass[] = "ѧ���ɼ�����ϵͳ";
	TCHAR szTitle[] = "ѧ���ɼ�����ϵͳ";
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