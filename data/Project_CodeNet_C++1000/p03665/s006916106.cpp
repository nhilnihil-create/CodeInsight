#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, p;

lli mypow(lli a, lli x){
	lli ret = 1;
	lli b = a;
	while(x > 0){
		if(x&1){
			ret*=a;
		}
		a*=a;
		x >>= 1;
	}
	return ret;
}

int main(void){
	cin >> n >> p;
	lli c, d;
	c = d = 0;
	rep(i, n){
		lli a;
		cin >> a;
		if(a&1) d++;
		else c++;
	}
	if(p == 1 && d == 0){
		cout << 0 << endl;
		return 0;
	}
	if(p == 0) cout << mypow(2, c)*mypow(2, d-1) << endl;
	else cout << mypow(2, c-1)*mypow(2, d) << endl;

	return 0;
}
