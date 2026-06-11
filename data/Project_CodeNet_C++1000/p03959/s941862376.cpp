#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n;
	cin >> n;
	vector<int> t(n), a(n);
	rep(i,n) cin >> t[i];
	rep(i,n) cin >> a[i];
	vector<int> mt(n, 0);
	int tmax = 0, amax = 0;
	ll ans = 1;
	rep(i,n){
		if(i!=n-1&&t[i]>t[i+1]){
			cout << 0 << endl;
			return 0;
		}
		if(tmax < t[i]){
			tmax = t[i];
			mt[i] = t[i];
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(i!=n-1&&a[i]<a[i+1]){
			cout << 0 << endl;
			return 0;
		}
		if(amax < a[i]){
			if((mt[i]!=0&&mt[i]!=a[i])||a[i]>t[i]){
				cout << 0 << endl;
				return 0;
			}
			mt[i] = a[i];
			amax = a[i]; 
		}
	}
	if(amax!=tmax){
		cout << 0 << endl;
		return 0;
	}
	rep(i,n){
		if(mt[i]!=0) continue;
		int p = min(a[i], t[i]);
		ans *= p;
		ans %= MOD;
	}
	cout << ans << endl;
}