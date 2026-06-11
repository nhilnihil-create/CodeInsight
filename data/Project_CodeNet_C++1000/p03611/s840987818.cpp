#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(a,b,n) for(ll a = (ll)(b); a < (ll)(n); a++)
#define mrep(i,n) for (ll i = (ll)(n); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n,s; cin >> n;
	vector<int> a(100001);
	rep(i,n) {
		cin >> s;
		a[s]++;
	}
	int ans=-1;
	rep(i,99999) {
		ans=max(ans,(a.at(i)+a.at(i+1)+a.at(i+2)));
	}
	cout << ans << endl;
}