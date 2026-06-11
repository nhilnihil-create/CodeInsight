#include <bits/stdc++.h>
////////////////////////////////////////////////////////////
#define all(x) (x).begin(), (x).end() 
const int inf = 1e9;
const long long INF=1e15;
#define endl '\n'
#define rep(i, n) for(int i=0;i<(n);++i)
#define repp(i, a, b) for(int i=(a);i<=(b);++i)
#define pb push_back
#define eb emplace_back
#define fastio ios::sync_with_stdio(false);cin.tie(0); //cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

void solve() {
	ll n; cin>>n;
	vll l(2*n);rep(i,2*n)cin>>l[i];
	sort(all(l));
	ll sum = 0;
	rep(i,n) sum += l[i*2];
	cout << sum;
}

int main() {
	fastio;
	solve();
}

