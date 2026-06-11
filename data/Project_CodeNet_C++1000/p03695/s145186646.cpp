//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<int>	aa(8);
	for(i=0;i<n;i++) {
		cin >> a;
		if (a > 3199) ans++;
		else if (a > 2799) aa[7] = 1;
		else if (a > 2399) aa[6] = 1;
		else if (a > 1999) aa[5] = 1;
		else if (a > 1599) aa[4] = 1;
		else if (a > 1199) aa[3] = 1;
		else if (a >  799) aa[2] = 1;
		else if (a >  399) aa[1] = 1;
		else aa[0] = 1;
	}
	m = 0;
	for(i=0;i<8;i++) {
		m += aa[i];
	}
	ans =  m + ans;
	if (m==0) m=1;
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << m << ' ' << ans << endl;
	return 0;
}
