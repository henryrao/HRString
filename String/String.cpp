// String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "HRString.h"


int _tmain(int argc, _TCHAR* argv[])
{
	HRString out("hr string!");
	HRString out2(out);
	HRString out3;
	HRString out4;
	out3 = out;
	out3 = out + out2;
	out4 += out2;
	out4 += out2;
	cout << out << endl;
	cout << out2 << endl;
	cout << out3 << endl;
	cout << out4 << endl;

	return 0;
}

