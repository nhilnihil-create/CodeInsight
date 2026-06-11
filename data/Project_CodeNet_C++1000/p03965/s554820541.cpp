#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
char s[N];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	
	int res = 0, g = 0, p = 0;
	for (int i = 0; i < n; i ++ )
		if (g == p)
		{
			g ++ ;
			if (s[i] == 'p') res -- ;
		}
		else
		{
			p ++ ;
			if (s[i] == 'g') res ++ ;
		}
	
	cout << res << endl;
	return 0;
}