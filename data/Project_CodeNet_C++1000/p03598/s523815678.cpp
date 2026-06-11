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
	cin >> n >> k;
	vector<ll>	aa(n);
	for(i=0;i<n;i++) cin >> aa[i];

	for(i=0;i<n;i++) {
		a = abs(k-aa[i]);
		b = aa[i];
		ans += min(a,b) * 2;
	}
	cout << ans << endl;
	return 0;
}
