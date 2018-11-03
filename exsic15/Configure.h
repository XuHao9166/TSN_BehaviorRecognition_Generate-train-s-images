#ifndef CONFIGURE_H
#define CONFIGURE_H

#ifdef WIN32
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#pragma warning(disable:4297)
#endif

#include <string>
#include <iostream>
#include <map>
#include "Exception.hpp"

class Configure : public std::map<std::string, std::string>
{
public:
	Configure();
	Configure(const std::string& prefix);
	virtual ~Configure();

	void Load(int argc, char** argv);
	void Load(std::istream& in);
	
	void Save(std::ostream& out);
	
	int GetInt(const std::string& property, int defaultValue);
	bool GetBool(const std::string& property, bool defaultValue);
	std::string GetString(const std::string& property,const char* defaultValue);
	
	int GetInt(const std::string& property) throw ();
	bool GetBool(const std::string& property) throw ();
	std::string GetString(const std::string& property) throw ();

	
protected:
	virtual void SubstituteVariables(std::string& value);

	/*! \brief �����ַ����Ƿ�ȫ��������
	 *  @param str �����Ե��ַ�����ʼ��ַ��C���
	 *  @return  �ַ��������ַ���true�����򷵻�false
	 */
	bool isnumstr(const char* s);

	/*! \brief ȥ���ַ����ұ�ָ�����ַ�
	 *  @param	str				�ַ�����ַ
	 *  @param  trimlets         ȥ���ַ������ַ�
	 *  @return				ȥ��ָ���ַ�����ַ���
	 */
	std::string rtrim(const std::string& str,const std::string& trimlets);

	/*! \brief ȥ���ַ����ұ�ָ�����ַ�
	 *  @param	str				�ַ�����ַ
	 *  @param  trimlet         ȥ���ַ������ַ�,Ĭ��Ϊ�ո�
	 *  @return				�ַ�����ʼ��ַ
	 */
	char* rtrim(char *s,const char trimlet);
	
	/*! \brief ȥ���ַ������ָ�����ַ�
	 *  @param	str				�ַ�����ַ
	 *  @param  trimlets         ȥ���ַ������ַ�
	 *  @return				ȥ��ָ������ַ���
	 */
	std::string ltrim(const std::string& str,const std::string& trimlets);

private:
	std::string m_prefix;
};

#endif