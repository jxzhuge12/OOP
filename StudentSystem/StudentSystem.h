/* *
* @copyright 2013-2014, Zhejiang University
* @file   StudentSystem
* @brief  ����ȫ�ֺ꼴ȫ�ֺ���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-06-15
*
*/
#ifndef _STUDENTSYSTEM_H
#define _STUDENTSYSTEM_H

#include <windows.h>
#include <tchar.h>
#include <sql.h>
#include <stdio.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string>
#include "resource.h"
using namespace std;

SQLRETURN retcode;
SQLHENV henv; //�������
SQLHDBC hdbc; //���Ӿ��
SQLHSTMT hstmt; //�����
OPENFILENAME ofn;
HANDLE hf;
string pBuffer;
HWND hWnd;
static HMENU hMenu;
DWORD RSize;
string ano;
int fileSize;
char *tempBuffer;

/**
* @brief       ���ܣ����ڴ�������
*/
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);

/**
* @brief       ���ܣ����ڽ�����Ϣѭ��
*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/**
* @brief       ���ܣ�����ͬ���ݿ������
* @param [in]  hwnd:hWnd
* @return      bool ��ȷ���Ƿ����ӳɹ�
* @exception
*/
BOOL OpenFileDialog(HWND hWnd);

#endif