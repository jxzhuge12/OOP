/* *
* @copyright 2013-2014, Zhejiang University
* @file   StudentSystem
* @brief  实现学生成绩的相关操作
*
* 版本历史：
* @Verson  0.1 @date 2014-06-15   
*
*/
#ifndef _SYSTEM_H //防止System.h被重复引用
#define _SYSTEM_H

#include <windows.h>
#include <tchar.h>
#include <sql.h>
#include <stdio.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string>
using namespace std;

//建立针对成绩操作的类
class System{
public:

	/**
	* @brief       功能：进行管理员登陆的操作
	* @param [in]  输入参数 pBuffer：string 表示输入的账号密码
	* @return      bool 以确认是否登陆成功
	* @exception
	*/
	bool admin_login(string pBuffer);

	/**
	* @brief       功能：进行成绩的单个录入操作
	* @param [in]  输入参数 pBuffer：string 表示输入的单个学生学号、姓名、学位代码、科目名称、成绩
	* @return      bool 以确认是否录入成功
	* @exception
	*/
	bool One_ent(string pBuffer);

	/**
	* @brief       功能：进行成绩的批量录入操作
	* @param [in]  输入参数 pBuffer：string 表示输入的若干个学生学号、姓名、学位代码、科目名称、成绩
	* @return      bool 以确认是否录入成功
	* @exception
	*/
	bool Many_ent(string pBuffer);

	/**
	* @brief       功能：按照不同学位来显示学生成绩
	* @param [in]  输入参数 chdegree：string 表示输入的学位代码：‘B’for bachelor，‘M’ for master，‘P’for PHD
	* @return      bool 以确认是否查询成功
	* @exception
	*/
	bool Student_search_degree(string chdegree);

	/**
	* @brief       功能：进行成绩查询
	* @param [in]  输入参数 pBuffer：string 表示输入的学生学号
	* @return      bool 以确认是否查询成功
	* @exception
	*/
	bool Student_search_stu(string pBuffer);

	/**
	* @brief       功能：进行成绩删除操作
	* @param [in]  输入参数 pBuffer：string 表示输入的学生学号及相应成绩
	* @return      bool 以确认是否删除成功
	* @exception
	*/
	bool Sub_de(string pBuffer);

	/**
	* @brief       功能：进行成绩的修改操作
	* @param [in]  输入参数 pBuffer：string 表示输入的学生学号、科目名称、成绩
	* @return      bool 以确认是否修改成功
	* @exception
	*/
	bool Sub_re(string pBuffer);
};

#endif