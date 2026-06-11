#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>

#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll mod = 998244353;



ll N,A,B,ans;
ll h[100001];

bool f(ll m) {
	ll cnt = 0;
	FOR(i, 0, N) {
		ll tmp = h[i] - B * m;
		if (tmp >= 0)cnt += (tmp + A - B - 1) / (A - B);
	}
	return (cnt <= m);

}

int main() {
	cin >>N>> A >> B;
	
	FOR(i, 0, N) {
		cin >> h[i];
	}
	ll ng = 0, ok = 1e9;

	while (ok - ng > 1) {
		ll mid = (ok + ng) / 2;
		if (f(mid))ok = mid;
		else ng = mid;
	}
	cout << ok << endl;

	return 0;
}