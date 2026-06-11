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

int g, p;
string s;

int main()
{
	cin >> s;
	
	int res = 0;
	for (auto u : s)
		if (p < g)
		{
			p ++ ;
			if (u == 'g') res ++ ;
		}
		else
		{
			g ++ ;
			if (u == 'p') res -- ;
		}
		
	cout << res << endl;
    return 0;
}