#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3, M = 55, mod = 1000000007;

int n;
char s[N][M];

int main()
{
	cin >> n;
	for (int i = 1; i < N; i ++ ) cin >> s[i] + 1;
	
	int i, last;
	LL res;
	if (s[1][1] == s[1][2]) res = 6, i = 3, last = 2;
	else res = 3, i = 2, last = 1;
	
	while (i <= n)
	{
		if (s[1][i] == s[1][i + 1])
		{
			if (last == 2) res = res * 3LL % mod;
			else res = res * 2LL % mod;
			last = 2;
			i += 2;
		}
		else
		{
			if (last == 1) res = res * 2LL % mod;
			last = 1;
			i ++ ;
		}
		// cout << res << endl;
	}
	cout << res << endl;
    return 0;
}
