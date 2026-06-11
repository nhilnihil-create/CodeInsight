#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <sstream>
#include <cstdio>

using namespace std;

#define ERROR_ID		0

#define PROCESS_ERROR(Condition)    \
{                                   \
		if (!(Condition))           \
		{                           \
			goto Exit0;             \
		}                           \
}

typedef unsigned char			BYTE;
typedef int						BOOL;
typedef unsigned long			DWORD;
typedef unsigned long long		ULLONG;

inline int read() {
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}//快读优化

int main(int argc, char* argv[])
{
	string			szWordStr;
	int				nLength;

	cin >> szWordStr;

	nLength = szWordStr.size();

	if (szWordStr[0] == szWordStr[nLength - 1])
	{
		if (nLength % 2 == 1)
		{
			cout << "Second" << endl;
		}
		else
		{
			cout << "First" << endl;
		}
	}
	else
	{
		if (nLength % 2 == 1)
		{
			cout << "First" << endl;
		}
		else
		{
			cout << "Second" << endl;
		}
	}
	return 0;
}
