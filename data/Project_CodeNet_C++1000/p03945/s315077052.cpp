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
	cin >> s;
	for(i=1;i<s.size();i++) {
		if (s[i-1] != s[i]) ans++;
	}

	cout << ans << endl;
	return 0;
}
