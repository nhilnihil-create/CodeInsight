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


	while((a%2)==0 && (b%2)==0 && (c%2)==0) {
		if (a==b && b==c) {
			cout << -1 << endl;
			return 0;
		}
		ans++;
		i = b/2 + c/2;
		j = a/2 + c/2;
		k = a/2 + b/2;
		a = i;
		b = j;
		c = k;
	}
	cout << ans << endl;
	return 0;
}
