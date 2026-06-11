#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll n,m;
ll x[300000],y[300000];
ll mod(ll x) {
	ll mod = 1e9+7;
	x %= mod;
	if(x < 0) {
		x = mod + x;
	}
	return x;
}
int main(){
	cin >> n >> m;

	REP(i,n) 
		cin >> x[i];
	REP(i,m) 
		cin >> y[i];

	ll X = 0;

	REP(i,n) {
		X += mod((-(n - (2 * i + 1))) * x[i]);
		X = mod(X);
	}

	ll Y = 0;

	REP(i,m) {
		Y += mod((-(m - (2 * i + 1))) * y[i]);
		Y = mod(Y);
	}

	cout << mod(X * Y) << endl;
	
	return 0;
}
