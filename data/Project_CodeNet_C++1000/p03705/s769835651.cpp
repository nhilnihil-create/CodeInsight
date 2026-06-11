#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	ll n,a,b;
	cin >> n >> a >> b;
	ll n2 = n-2;
	ll ans;
	if(a>b) ans=0;
	else if(n==1&&a!=b) ans=0; 
	else if(n==1&&a==b) ans=1; 
	else ans = n2*b-n2*a+1;
	cout << ans << endl;
	return 0;
}

