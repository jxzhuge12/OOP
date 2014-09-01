/* *
* @copyright 2013-2014, Zhejiang University
* @file   StudentSystem
* @brief  ʵ��ѧ���ɼ�����ز���
*
* �汾��ʷ��
* @Verson  0.1 @date 2014-06-15   
*
*/
#ifndef _SYSTEM_H //��ֹSystem.h���ظ�����
#define _SYSTEM_H

#include <windows.h>
#include <tchar.h>
#include <sql.h>
#include <stdio.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string>
using namespace std;

//������Գɼ���������
class System{
public:

	/**
	* @brief       ���ܣ����й���Ա��½�Ĳ���
	* @param [in]  ������� pBuffer��string ��ʾ������˺�����
	* @return      bool ��ȷ���Ƿ��½�ɹ�
	* @exception
	*/
	bool admin_login(string pBuffer);

	/**
	* @brief       ���ܣ����гɼ��ĵ���¼�����
	* @param [in]  ������� pBuffer��string ��ʾ����ĵ���ѧ��ѧ�š�������ѧλ���롢��Ŀ���ơ��ɼ�
	* @return      bool ��ȷ���Ƿ�¼��ɹ�
	* @exception
	*/
	bool One_ent(string pBuffer);

	/**
	* @brief       ���ܣ����гɼ�������¼�����
	* @param [in]  ������� pBuffer��string ��ʾ��������ɸ�ѧ��ѧ�š�������ѧλ���롢��Ŀ���ơ��ɼ�
	* @return      bool ��ȷ���Ƿ�¼��ɹ�
	* @exception
	*/
	bool Many_ent(string pBuffer);

	/**
	* @brief       ���ܣ����ղ�ͬѧλ����ʾѧ���ɼ�
	* @param [in]  ������� chdegree��string ��ʾ�����ѧλ���룺��B��for bachelor����M�� for master����P��for PHD
	* @return      bool ��ȷ���Ƿ��ѯ�ɹ�
	* @exception
	*/
	bool Student_search_degree(string chdegree);

	/**
	* @brief       ���ܣ����гɼ���ѯ
	* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ��
	* @return      bool ��ȷ���Ƿ��ѯ�ɹ�
	* @exception
	*/
	bool Student_search_stu(string pBuffer);

	/**
	* @brief       ���ܣ����гɼ�ɾ������
	* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ�ż���Ӧ�ɼ�
	* @return      bool ��ȷ���Ƿ�ɾ���ɹ�
	* @exception
	*/
	bool Sub_de(string pBuffer);

	/**
	* @brief       ���ܣ����гɼ����޸Ĳ���
	* @param [in]  ������� pBuffer��string ��ʾ�����ѧ��ѧ�š���Ŀ���ơ��ɼ�
	* @return      bool ��ȷ���Ƿ��޸ĳɹ�
	* @exception
	*/
	bool Sub_re(string pBuffer);
};

#endif