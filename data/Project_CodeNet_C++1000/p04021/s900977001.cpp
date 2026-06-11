#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()
 
 
using namespace std;
 
const ll N = 4e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;
 
ll n;
ll a[N], b[N], dp[N], ans;
vector<ll> x;
int main() {
	speed;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		x.pb(a[i]);
	}
	sort(all(x));
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(x), a[i]) - x.begin() + 1;
		ans += (a[i] % 2 != i %2);
	}
	cout << ans / 2;
}
 
/*
4
1 2 3 4
*/