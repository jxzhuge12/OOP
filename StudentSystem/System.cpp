#include "System.h"

extern SQLRETURN retcode;
extern SQLHENV henv; //环境句柄
extern SQLHDBC hdbc; //连接句柄
extern SQLHSTMT hstmt; //语句句柄
extern HWND hWnd;
extern string ano;

/**
* @brief       功能：进行管理员登陆的操作
* @param [in]  输入参数 pBuffer：string 表示输入的账号密码
* @return      bool 以确认是否登陆成功
* @exception
*/
bool System::admin_login(string pBuffer)
{
	ano = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string password = pBuffer;

	string select = "SELECT ano FROM administrator WHERE (ano = '" + ano + "')";
	const char * tempSelect = select.c_str();
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "句柄分配失败！", "管理员登陆", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "用户名不存在！", "管理员登陆", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

	string select2 = "SELECT ano FROM administrator WHERE (ano = '" + ano + "' and password = '" + password + "')";
	const char * tempSelect2 = select2.c_str();
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect2, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "句柄分配失败！", "管理员登陆", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "密码错误！", "管理员登陆", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       功能：进行成绩的单个录入操作
* @param [in]  输入参数 pBuffer：string 表示输入的单个学生学号、姓名、学位代码、科目名称、成绩
* @return      bool 以确认是否录入成功
* @exception
*/
bool System::One_ent(string pBuffer)
{
	//将输入的文本转换成Sql语言
	string ID = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Name = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Sub = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Grade = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Degree = pBuffer;

	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		string query = "INSERT INTO Student VALUES('" + ID + "','" + Name + "','" + Degree + "','" + Sub + "'," + Grade + ")";
		const char * tempQuery = query.c_str();
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempQuery, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "录入失败！", "单个录入", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       功能：进行成绩的批量录入操作
* @param [in]  输入参数 pBuffer：string 表示输入的若干个学生学号、姓名、学位代码、科目名称、成绩
* @return      bool 以确认是否录入成功
* @exception
*/
bool System::Many_ent(string pBuffer)
{
	while (pBuffer.length() <= 3)
	{
		//将输入的文本转换成Sql语言
		string ID = pBuffer.substr(0, pBuffer.find(','));
		pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
		string Name = pBuffer.substr(0, pBuffer.find(','));
		pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
		string Sub = pBuffer.substr(0, pBuffer.find(','));
		pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
		string Grade = pBuffer.substr(0, pBuffer.find(','));
		pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
		string Degree = pBuffer.substr(0, pBuffer.find(','));
		pBuffer = pBuffer.substr(pBuffer.find('\n') + 1);

		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		{
			string query = "INSERT INTO Student VALUES('" + ID + "','" + Name + "','" + Degree + "','" + Sub + "'," + Grade + ")";
			const char * tempQuery = query.c_str();
			retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempQuery, SQL_NTS);
		}
		if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
		{
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
			MessageBox(hWnd, "录入失败！", "批量录入", MB_OK);
			return false;
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	}
	return true;
}

/**
* @brief       功能：按照不同学位来显示学生成绩
* @param [in]  输入参数 chdegree：string 表示输入的学位代码：‘B’for bachelor，‘M’ for master，‘P’for PHD
* @return      bool 以确认是否查询成功
* @exception
*/
bool System::Student_search_degree(string chdegree)
{
	char ID[11] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Name[21] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Sub[41] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Grade[4] = { '0', '0', '0', '0' };
	char Degree[2] = { '0', '0' };
	int lent1, lent2, lent3, lent4, lent5;
	//将输入的文本转换成Sql语言
	string select = "SELECT * FROM book WHERE (Degree = '" + chdegree + "')";
	const char * tempSelect = select.c_str();
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	//定位数据
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
		SQLBindCol(hstmt, 1, SQL_C_CHAR, ID, 11, (SQLINTEGER*) &lent1);
		SQLBindCol(hstmt, 2, SQL_C_CHAR, Name, 21, (SQLINTEGER*) &lent2);
		SQLBindCol(hstmt, 3, SQL_C_CHAR, Degree, 2, (SQLINTEGER*) &lent3);
		SQLBindCol(hstmt, 4, SQL_C_CHAR, Sub, 41, (SQLINTEGER*) &lent4);
		SQLBindCol(hstmt, 5, SQL_C_CHAR, Grade, 21, (SQLINTEGER*) &lent5);

		while (SQLFetch(hstmt) != SQL_NO_DATA)
		{
			SQLGetData(hstmt, 1, SQL_C_CHAR, ID, 11, (SQLINTEGER*) &lent1);
			SQLGetData(hstmt, 2, SQL_C_CHAR, Name, 21, (SQLINTEGER*) &lent2);
			SQLGetData(hstmt, 3, SQL_C_CHAR, Degree, 2, (SQLINTEGER*) &lent3);
			SQLGetData(hstmt, 4, SQL_C_CHAR, Sub, 41, (SQLINTEGER*) &lent4);
			SQLGetData(hstmt, 5, SQL_C_CHAR, Grade, 21, (SQLINTEGER*) &lent5);
			//建立SQL的数据输出语言
			string result = "学号\t\t" + (string) ID + "\n姓名\t\t" + (string) Name + "\n科目\t\t" + (string) Sub + "\n成绩\t\t" + (string) Grade + "\n";
			const char * tempResult = result.c_str();
			MessageBox(hWnd, tempResult, "查询结果", MB_OK);
		}
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       功能：进行成绩查询
* @param [in]  输入参数 pBuffer：string 表示输入的学生学号
* @return      bool 以确认是否查询成功
* @exception
*/
bool System::Student_search_stu(string pBuffer)
{
	char ID[11] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Name[21] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Sub[41] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char Grade[4] = { '0', '0', '0', '0' };
	char Degree[2] = { '0', '0' };
	int lent1, lent2, lent3, lent4, lent5;
	//将输入的文本转换成Sql语言
	string select = "SELECT * FROM Student WHERE (ID = '" + pBuffer + "')";
	const char * tempSelect = select.c_str();
	//定位数据
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
		SQLBindCol(hstmt, 1, SQL_C_CHAR, ID, 11, (SQLINTEGER*) &lent1);
		SQLBindCol(hstmt, 2, SQL_C_CHAR, Name, 21, (SQLINTEGER*) &lent2);
		SQLBindCol(hstmt, 3, SQL_C_CHAR, Degree, 2, (SQLINTEGER*) &lent3);
		SQLBindCol(hstmt, 4, SQL_C_CHAR, Sub, 41, (SQLINTEGER*) &lent4);
		SQLBindCol(hstmt, 5, SQL_C_CHAR, Grade, 21, (SQLINTEGER*) &lent5);

		while (SQLFetch(hstmt) != SQL_NO_DATA)
		{
			SQLGetData(hstmt, 1, SQL_C_CHAR, ID, 11, (SQLINTEGER*) &lent1);
			SQLGetData(hstmt, 2, SQL_C_CHAR, Name, 21, (SQLINTEGER*) &lent2);
			SQLGetData(hstmt, 3, SQL_C_CHAR, Degree, 2, (SQLINTEGER*) &lent3);
			SQLGetData(hstmt, 4, SQL_C_CHAR, Sub, 41, (SQLINTEGER*) &lent4);
			SQLGetData(hstmt, 5, SQL_C_CHAR, Grade, 21, (SQLINTEGER*) &lent5);
			//建立SQL输出语句
			string result = "科目\t\t" + (string) Sub + "\n成绩\t\t" + (string) Grade + "\n";
			const char * tempResult = result.c_str();
			MessageBox(hWnd, tempResult, "查询结果", MB_OK);
		}
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       功能：进行成绩删除操作
* @param [in]  输入参数 pBuffer：string 表示输入的学生学号及相应成绩
* @return      bool 以确认是否删除成功
* @exception
*/
bool System::Sub_de(string pBuffer)
{
	//将输入的文本转换成Sql语言
	string ID = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Sub = pBuffer;
	string select = "SELECT * FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
	const char * tempSelect = select.c_str();
	//确定数据存在
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		MessageBox(hWnd, "系统错误！", "成绩删除", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		MessageBox(hWnd, "不存在符合条件的结果！\n删除失败！", "成绩删除", MB_OK);
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	//进行删除操作，建立SQL删除语句
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		string query = "DELETE FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
		const char * tempQuery = query.c_str();

		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempQuery, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "删除失败！", "成绩删除", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       功能：进行成绩的修改操作
* @param [in]  输入参数 pBuffer：string 表示输入的学生学号、科目名称、成绩
* @return      bool 以确认是否修改成功
* @exception
*/
bool System::Sub_re(string pBuffer)
{
	//将输入的文本转换成Sql语言
	string ID = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Sub = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Grade = pBuffer;
	string select = "SELECT * FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
	const char * tempSelect = select.c_str();
	//确认成绩存在
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		MessageBox(hWnd, "修改失败！", "成绩修改", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		MessageBox(hWnd, "不存在符合条件的结果！\n修改失败！", "成绩修改", MB_OK);
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	//进行修改操作，建立SQLset语句
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		string update1 = "UPDATE Student SET Grade = " + Grade + " FROM Student WHERE (ID = '" + ID + "') AND (Sub ='" + Sub + ")";
		const char * tempUpdate1 = update1.c_str();
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempUpdate1, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "修改失败！", "成绩修改", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}
