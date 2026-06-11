#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i <= (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main(){
	ll n; cin >> n;
	set<int> s;
	rep(i,n) {
		int a; cin >> a;
		if(s.count(a)) s.erase(a);
		else s.insert(a);
	}
	cout << s.size() << endl;
}