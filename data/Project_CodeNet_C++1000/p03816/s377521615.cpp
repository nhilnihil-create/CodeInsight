#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <set>

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
typedef long long				LLONG;

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

int			g_nNumberArrays[100010];

int main(int argc, char* argv[])
{
	int			nNumberCount;
	int			nCount;

	cin >> nNumberCount;

	for (int i = 1; i <= nNumberCount; i++)
	{
		cin >> g_nNumberArrays[i];
	}
	sort(g_nNumberArrays + 1, g_nNumberArrays + 1 + nNumberCount);

	for (int i = 2; i <= nNumberCount; i++)
	{
		if (g_nNumberArrays[i] == g_nNumberArrays[i - 1])
		{
			nCount++;
		}
	}

	if (nCount & 1)
	{
		nCount++;
	}
	cout << nNumberCount - nCount << endl;
	return 0;
}