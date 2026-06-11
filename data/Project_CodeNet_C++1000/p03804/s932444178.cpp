//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

ll n,m;
vector<string> A(50),B(50);

bool isok(ll i, ll j) {
	ll x,y;
	for(x=0;x<m;x++) {
		for(y=0;y<m;y++) {
			if (A[i+x][j+y] != B[x][y] ) return false;
		}
	}
	return true;
}
int main() {
	ll		a,b,c,h,i,j,k,l,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> m;

	for(i=0;i<n;i++) cin >> A[i];
	for(i=0;i<m;i++) cin >> B[i];

	bool ok;
	for(i=0;i<=(n-m);i++) {
		for(j=0;j<=(n-m);j++) {
			ok = isok(i,j);
			if (ok) break;
		}
		if (ok) break;
	}
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	if (ok) {
		cout << "Yes" << endl;
	}	else {
		cout << "No" << endl;
	}
	return 0;
}
