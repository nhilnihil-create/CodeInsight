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
LL l, r;

int main()
{
	cin >> n;
	l = r = 1LL;
	
	while (n -- )
	{
		LL a, b;
		cin >> a >> b;
		
		LL t1 = (l + a - 1LL) / a;
		LL t2 = (r + b - 1LL) / b;
		LL t = max(t1, t2);
		
		l = t * a;
		r = t * b;
	}
	
	cout << l + r << endl;
    return 0;
}