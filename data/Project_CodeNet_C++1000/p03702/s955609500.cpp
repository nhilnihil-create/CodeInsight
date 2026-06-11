#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

typedef long long ll;
ll n,a,b,A[100050];

bool test(ll t){
	ll tries = 0;
	for(ll i = 0; i<n; i++){
		if(A[i] >= b*t) tries += (A[i]-b*t)/a + ((A[i]-b*t)%a != 0);
	}
	return tries <= t;
}

int main(){
//	freopen("widespread.in","r",stdin);
	cin >> n >> a >> b;
	a -= b;
	for(ll i = 0; i<n; i++) cin >> A[i];
	ll s = 0, e = inf, m;
	while(m = (s+e)/2, e-s>1){
		if(test(m)) e=m;
		else s=m;
	}
	cout << e;
}
