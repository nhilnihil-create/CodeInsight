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
	int a,b,c; cin >> a >> b >> c;
	if (a + b == c)
		cout << "Yes" << endl;
	else if (a + c == b)
		cout << "Yes" << endl;
	else if (b + c == a)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
