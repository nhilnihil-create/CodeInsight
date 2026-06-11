#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
	int f = 1, x = 0;
	char ch;

	do{
		ch = getchar();
		if (ch == '-')
			f = -1;
	}while(ch < '0' || ch > '9');
	do{
		x = x * 10 + ch - '0';
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return f * x;
}
const int N = 100;

int n, l;
string a[N + 1];

inline bool compare(string a, string b)
{
	return a < b;
}
int main()
{
	n = read();
	l = read();
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1, compare);

	for (int i = 1; i <= n; i++)
		cout << a[i];
	printf("\n");
	return 0;
}
