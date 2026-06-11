//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	string	ans = "No";
	cin >> n >> m >> k;
	for(i=0;i<=n;i++) for(j=0;j<=m;j++) {
		x = i*(m-j) + j*(n-i);
		if (x==k) ans = "Yes";
	}

	cout << ans << endl;
	return 0;
}
