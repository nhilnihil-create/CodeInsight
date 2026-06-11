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
	cin >> a >> b >> c;

	for(i=1;i<=b;i++) {
		if ( (i*a % b) == c ) ans = 1;
	}

	if (ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
