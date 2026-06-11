#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = 4*atan(1);
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const string YES = "Possible";
const string NO = "Impossible";
#define pb push_back
#define mp make_pair

ll X;

void solve()
{
	ll cur = 0;
	for(int i=1; ; ++i){
		cur += i;
		if(cur >= X){
			cout << i << endl;
			break;
		}
	}
}

int main()
{
	cin >> X;
	solve();
}