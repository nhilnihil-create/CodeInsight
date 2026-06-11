#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli q, h, s, d, n;

int main(void){
	cin >> q >> h >> s >> d >> n;
	lli x = min({4*q, 2*h, s});
	lli y = d;
	lli ans = 0;
	if(2*x > y){
		ans = n/2*y+n%2*x;
	}else{
		ans = n*x;
	}
	cout << ans << endl;
	return 0;
}
