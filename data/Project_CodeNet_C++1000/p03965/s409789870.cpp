#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

string s;

int main()
{
	cin >> s;
	
	int res = 0, g = 0, p = 0;
	for (int i = 0; i < s.size(); i ++ )
		if (g <= p)
		{
			g ++ ;
			res -= s[i] == 'p';
		}
		else
		{
			p ++ ;
			res += s[i] == 'g';
		}
	
	cout << res << endl;
	return 0;
}