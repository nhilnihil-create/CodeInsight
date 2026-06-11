#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll M = 998244353;
const int N = 1e5+5;
const int K = 3000;
const ll INF = 1e18;
const double EPS = 1e-6;

string s;
ll n,a[N],b[N],c[N],cnt,mx,mn;
map <ll,int> m, z;
vector <ll> v;

int main () {
	faster
	cin>>n;
	for (int i = 1; i<=n; i++) {
		cin>>a[i];
		if (m[a[i]] == 0) {
			cnt++;
			m[a[i]]++;
			v.pb(a[i]);
		}
	}
	if (cnt>2) {
		cout<<"No";
		return 0;
	}
	if (v.size() == 1) {
		if (v[0]*2 <= n || v[0] == n-1) cout<<"Yes";
		else cout<<"No";
		return 0;
	}
	ll q = v[0], w = v[1];
	if (q>w) swap(q,w);
	for (int i = 1; i<=n; i++) {
		if (a[i] == q) mn++;
		else mx++;
	}
	if (q >= mn && 2*(w - mn) <= mx) {
		cout<<"Yes";
	}
	else cout<<"No";

    return 0;
}
