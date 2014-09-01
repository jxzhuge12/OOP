#include "System.h"

extern SQLRETURN retcode;
extern SQLHENV henv; //�������
extern SQLHDBC hdbc; //���Ӿ��
extern SQLHSTMT hstmt; //�����
extern HWND hWnd;
extern string ano;

/**
* @brief       ���ܣ����й���Ա��½�Ĳ���
* @param [in]  ������� pBuffer��string ��ʾ������˺�����
* @return      bool ��ȷ���Ƿ��½�ɹ�
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
		MessageBox(hWnd, "�������ʧ�ܣ�", "����Ա��½", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "�û��������ڣ�", "����Ա��½", MB_OK);
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
		MessageBox(hWnd, "�������ʧ�ܣ�", "����Ա��½", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "�������", "����Ա��½", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       ���ܣ����гɼ��ĵ���¼�����
* @param [in]  ������� pBuffer��string ��ʾ����ĵ���ѧ��ѧ�š�������ѧλ���롢��Ŀ���ơ��ɼ�
* @return      bool ��ȷ���Ƿ�¼��ɹ�
* @exception
*/
bool System::One_ent(string pBuffer)
{
	//��������ı�ת����Sql����
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
		MessageBox(hWnd, "¼��ʧ�ܣ�", "����¼��", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       ���ܣ����гɼ�������¼�����
* @param [in]  ������� pBuffer��string ��ʾ��������ɸ�ѧ��ѧ�š�������ѧλ���롢��Ŀ���ơ��ɼ�
* @return      bool ��ȷ���Ƿ�¼��ɹ�
* @exception
*/
bool System::Many_ent(string pBuffer)
{
	while (pBuffer.length() <= 3)
	{
		//��������ı�ת����Sql����
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
			MessageBox(hWnd, "¼��ʧ�ܣ�", "����¼��", MB_OK);
			return false;
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	}
	return true;
}

/**
* @brief       ���ܣ����ղ�ͬѧλ����ʾѧ���ɼ�
* @param [in]  ������� chdegree��string ��ʾ�����ѧλ���룺��B��for bachelor����M�� for master����P��for PHD
* @return      bool ��ȷ���Ƿ��ѯ�ɹ�
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
	//��������ı�ת����Sql����
	string select = "SELECT * FROM book WHERE (Degree = '" + chdegree + "')";
	const char * tempSelect = select.c_str();
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	//��λ����
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
			//����SQL�������������
			string result = "ѧ��\t\t" + (string) ID + "\n����\t\t" + (string) Name + "\n��Ŀ\t\t" + (string) Sub + "\n�ɼ�\t\t" + (string) Grade + "\n";
			const char * tempResult = result.c_str();
			MessageBox(hWnd, tempResult, "��ѯ���", MB_OK);
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
* @brief       ���ܣ����гɼ���ѯ
* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ��
* @return      bool ��ȷ���Ƿ��ѯ�ɹ�
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
	//��������ı�ת����Sql����
	string select = "SELECT * FROM Student WHERE (ID = '" + pBuffer + "')";
	const char * tempSelect = select.c_str();
	//��λ����
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
			//����SQL������
			string result = "��Ŀ\t\t" + (string) Sub + "\n�ɼ�\t\t" + (string) Grade + "\n";
			const char * tempResult = result.c_str();
			MessageBox(hWnd, tempResult, "��ѯ���", MB_OK);
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
* @brief       ���ܣ����гɼ�ɾ������
* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ�ż���Ӧ�ɼ�
* @return      bool ��ȷ���Ƿ�ɾ���ɹ�
* @exception
*/
bool System::Sub_de(string pBuffer)
{
	//��������ı�ת����Sql����
	string ID = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Sub = pBuffer;
	string select = "SELECT * FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
	const char * tempSelect = select.c_str();
	//ȷ�����ݴ���
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		MessageBox(hWnd, "ϵͳ����", "�ɼ�ɾ��", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		MessageBox(hWnd, "�����ڷ��������Ľ����\nɾ��ʧ�ܣ�", "�ɼ�ɾ��", MB_OK);
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	//����ɾ������������SQLɾ�����
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		string query = "DELETE FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
		const char * tempQuery = query.c_str();

		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempQuery, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "ɾ��ʧ�ܣ�", "�ɼ�ɾ��", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}

/**
* @brief       ���ܣ����гɼ����޸Ĳ���
* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ�š���Ŀ���ơ��ɼ�
* @return      bool ��ȷ���Ƿ��޸ĳɹ�
* @exception
*/
bool System::Sub_re(string pBuffer)
{
	//��������ı�ת����Sql����
	string ID = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Sub = pBuffer.substr(0, pBuffer.find(','));
	pBuffer = pBuffer.substr(pBuffer.find(' ') + 1);
	string Grade = pBuffer;
	string select = "SELECT * FROM Student WHERE (ID = '" + ID + "') and (Sub ='" + Sub + "')";
	const char * tempSelect = select.c_str();
	//ȷ�ϳɼ�����
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempSelect, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		MessageBox(hWnd, "�޸�ʧ�ܣ�", "�ɼ��޸�", MB_OK);
		return false;
	}
	if (SQLFetch(hstmt) == SQL_NO_DATA){
		MessageBox(hWnd, "�����ڷ��������Ľ����\n�޸�ʧ�ܣ�", "�ɼ��޸�", MB_OK);
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	//�����޸Ĳ���������SQLset���
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
		string update1 = "UPDATE Student SET Grade = " + Grade + " FROM Student WHERE (ID = '" + ID + "') AND (Sub ='" + Sub + ")";
		const char * tempUpdate1 = update1.c_str();
		retcode = SQLExecDirect(hstmt, (SQLCHAR*) tempUpdate1, SQL_NTS);
	}
	if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO){
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		MessageBox(hWnd, "�޸�ʧ�ܣ�", "�ɼ��޸�", MB_OK);
		return false;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return true;
}
