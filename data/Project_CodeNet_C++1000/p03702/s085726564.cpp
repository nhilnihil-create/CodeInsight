// ConsoleApplication69.cpp : アプリケーションのエントリ ポイントを定義します。

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define output(x) cout<<x<<endl;
typedef long long int ll;
ll  i, j, k, l, m, sum, flag, N, x, y, M, K, H, W,A,B;
ll h[100001];
bool check(ll x) {
	ll c = 0;
	REP(i, 0, N) {
		H = h[i] - x * B;
		if (H < 0)continue;
		if (H % A != 0)
			c += H / A + 1;
		else
			c += H / A;
	}
	return c <= x;
	
}

int main()
{

	sum = 0;
	flag = 0;
	cin >>N>> A >> B;
	A -= B;
	REP(i, 0, N) {
		cin >> h[i];
	}
	ll ng = 0;
	ll ok = 1000000000;

	while (ng + 1 != ok) {
		x = (ng + ok) / 2;
		if (check(x)) {
			ok = x;
		}
		else
			ng = x;
	}
	output(ok);
	return 0;
}











