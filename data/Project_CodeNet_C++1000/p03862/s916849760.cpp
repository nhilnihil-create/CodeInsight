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
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	ll ans = 0;
	rep(i,n-1){
		if(a[i]+a[i+1]<=x) continue;
		int p = a[i+1];
		a[i+1] = max(0, x-a[i]);
		ans += p - a[i+1];
		if(x==a[i+1]+a[i]) continue;
		else{
			ans += a[i] - x;
		}
	}
	cout << ans << endl;
}