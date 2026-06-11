#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	int a,b,c,d; cin >> a >> b >> c >> d;
	if ((c >= a && c <= b) || (b >= c && b <= d) || (a >= c && a <= d))
		cout << abs(max(a, c) - min(b, d)) << endl;
	else
		cout << 0 << endl;
	return 0;
}
