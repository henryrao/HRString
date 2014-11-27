#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class HRString
{
public:
	HRString(const char* pstr=NULL);
	HRString(const HRString& str);
	HRString& operator=(const HRString& str);
	~HRString();

	HRString operator+(const HRString& str) const;
	HRString& operator+=(const HRString& str);
	bool operator==(const HRString& str);
	char& operator[](unsigned int index);

	friend ostream& operator<<(ostream& os, HRString& str);
	friend istream& operator>>(istream& is, HRString& str);

	unsigned short size();
	const char* c_str() const;
private:
	char* m_str;
};

