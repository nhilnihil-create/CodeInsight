#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
string yes = "Yes\n";
string no = "No\n";

int  main()
{
	int a,b,x; cin >> x >> a >> b;
	if (a >= b)
	{
		cout << "delicious"; return 0;
	}
	if (b - a <= x)
		cout << "safe";
	else
		cout << "dangerous";
	return (0);
}