/* *
* @copyright 2013-2014, Zhejiang University
* @file   StudentSystem
* @brief  定义全局宏即全局函数
*
* 版本历史：
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
SQLHENV henv; //环境句柄
SQLHDBC hdbc; //连接句柄
SQLHSTMT hstmt; //语句句柄
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
* @brief       功能：用于创建窗口
*/
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);

/**
* @brief       功能：用于建立消息循环
*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/**
* @brief       功能：用于同数据库的连接
* @param [in]  hwnd:hWnd
* @return      bool 以确认是否连接成功
* @exception
*/
BOOL OpenFileDialog(HWND hWnd);

#endif