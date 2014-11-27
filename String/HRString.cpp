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

/*这里是要重新赋值，因此选判断是否已经赋了要引用的对象。*/
/*如果不是，则应该先清除当前的对象，然后再重新赋值*/
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
//该函数功能主要是临时合并一个字符串对象，然后返回
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

//该函数功能主要是临时合并一个字符串对象，然后赋值给当前对象
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

//判断是否相等
bool HRString::operator==(const HRString& str)
{
	//如果长度不相同，肯定不相等
	if (strlen(m_str) != strlen(str.m_str))
	{
		return false;
	}
	return strcmp(m_str,str.m_str)?false:true;
}

//支持下标索引操作
char& HRString::operator[](unsigned int index)
{
	if (index >= 0 && index <strlen(m_str))
	{
		return m_str[index];
	}
	else{
		cout << "invalid index：" <<index<< endl;
		exit(0);
	}
}

//友元操作,先输出到标准输出管道，至于标准输出管道常用显示在控制台（也可以是文件）
ostream& operator<<(ostream& os, HRString& str)
{
	os << str.m_str;
	return os;
}

istream& operator>>(istream& is, HRString& str)
{
	char tmp[1024] = {0};
	is >> tmp;//先从标准输入管道中获取数据
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