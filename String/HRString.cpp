#include "HRString.h"


HRString::~HRString()
{
	delete[] m_str;
	m_str = NULL;
}

HRString::HRString(const char* pstr)
{
	if (!pstr)
	{
		m_str = NULL;
	}
	else
	{
		m_str = new char[strlen(pstr)+1];
		strcpy(m_str, pstr);
	}
}

HRString::HRString(const HRString& str)
{
	if (!str.m_str)
	{
		m_str = NULL;
	}
	else
	{
		m_str = new char[strlen(str.m_str) + 1];
		strcpy(m_str, str.m_str);
	}
}

/*������Ҫ���¸�ֵ�����ѡ�ж��Ƿ��Ѿ�����Ҫ���õĶ���*/
/*������ǣ���Ӧ���������ǰ�Ķ���Ȼ�������¸�ֵ*/
HRString& HRString::operator=(const HRString& str)
{
	if (this != &str)
	{
		delete[] m_str;
		if (!str.m_str)
		{
			m_str = NULL;
		}
		else
		{
			m_str = new char[strlen(str.m_str)+1];
			strcpy(m_str, str.m_str);
		}
	}

	return *this;
}

//override 
//�ú���������Ҫ����ʱ�ϲ�һ���ַ�������Ȼ�󷵻�
HRString HRString::operator+(const HRString& str) const
{
	HRString tmpString;
	if (!str.m_str)
	{
		tmpString = *this;
	}
	else if (!m_str)
	{
		tmpString = str;
	}
	else{
		tmpString.m_str = new char[strlen(m_str) + strlen(str.m_str) + 1];
		strcpy(tmpString.m_str, m_str);
		strcat(tmpString.m_str, str.m_str);
	}
	return tmpString;
}

//�ú���������Ҫ����ʱ�ϲ�һ���ַ�������Ȼ��ֵ����ǰ����
HRString& HRString::operator+=(const HRString& str)
{
	if (!str.m_str)
	{
		return *this;
	}
	else if (!m_str)
	{
		m_str = new char[strlen(str.m_str)+1];
		strcpy(m_str, str.m_str);
	}
	else{
		HRString tmpString;
		tmpString.m_str = new char[strlen(m_str) + strlen(str.m_str) + 1];
		strcpy(tmpString.m_str, m_str);
		strcat(tmpString.m_str, str.m_str);
		m_str = tmpString.m_str;
		tmpString.m_str = NULL;
	}
	
	return *this;
}

//�ж��Ƿ����
bool HRString::operator==(const HRString& str)
{
	//������Ȳ���ͬ���϶������
	if (strlen(m_str) != strlen(str.m_str))
	{
		return false;
	}
	return strcmp(m_str,str.m_str)?false:true;
}

//֧���±���������
char& HRString::operator[](unsigned int index)
{
	if (index >= 0 && index <strlen(m_str))
	{
		return m_str[index];
	}
	else{
		cout << "invalid index��" <<index<< endl;
		exit(0);
	}
}

//��Ԫ����,���������׼����ܵ������ڱ�׼����ܵ�������ʾ�ڿ���̨��Ҳ�������ļ���
ostream& operator<<(ostream& os, HRString& str)
{
	os << str.m_str;
	return os;
}

istream& operator>>(istream& is, HRString& str)
{
	char tmp[1024] = {0};
	is >> tmp;//�ȴӱ�׼����ܵ��л�ȡ����
	str.m_str = new char[strlen(tmp)+1];
	strcpy(str.m_str, tmp);
	return is;
}

unsigned short HRString::size()
{
	return strlen(m_str);
}

const char* HRString::c_str() const
{
	return m_str;
}