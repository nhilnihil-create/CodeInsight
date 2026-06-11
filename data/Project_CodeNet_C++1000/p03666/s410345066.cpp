#include <bits/stdc++.h>
// #include <atcoder/mincostflow>
// using namespace atcoder;
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;
ll  LINF = 1e18;



int main(){
	int n;
	ll a,b,c,d;cin >> n >> a >> b >> c >> d;
	--n;
	bool flag = false;
	for(int i = 0;2*i <= n;i++){
		ll diff1 = abs(b-a) - i*abs(c-d);
		ll diff2 = abs(b-a) + i*abs(c-d);
		ll step = ll(n-2*i);
		if(diff1>=c*step &&diff1 <= d*step) flag = true;
		if(diff2>=c*step &&diff2 <= d*step) flag = true;
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}