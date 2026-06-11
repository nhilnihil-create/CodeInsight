#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 13;

int g, p;
string s;

int main()
{
	cin >> s;
	
	int res = 0;
	for (int i = 0; i < s.size(); i ++ )
		if (p + 1 <= g)
		{
			p ++ ;
			if (s[i] == 'g') res ++ ;
		}
		else
		{
			g ++ ;
			if (s[i] == 'p') res -- ;
		}
	cout << res << endl;
	return 0;
}