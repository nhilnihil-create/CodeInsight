#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int a[1001];

void func(int X){
	int x = X;
	for(int i=2; i*i<=X; ++i){
		if(x%i!=0) continue;
		while(x%i==0){
			a[i]++;
			x /= i;
		}
	}
	if(x != 1) a[x]++;
}

int main(){
	int n;
	cin >> n;
	FOR(i,2,n+1){
		func(i);
	}
	
	const ll mod = 1000000007;
	ll ans = 1;
	FOR(i,2,n+1){
		if(a[i]==0) continue;
		ans *= a[i]+1;
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}