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
	int x,a,b; cin >> x >> a >> b;
	if (abs(x-a) < abs(x-b))
		cout << "A";
	else
		cout << "B";
	return (0);
}