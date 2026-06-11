#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



ll n, m;
ll a[maxn];

vector<pair<ll,ll>> v;


vector<pair<ll,ll>> ev[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
	cin>>a[i];
	--a[i];
    }

    for (int i=0; i+1<n; i++) {
	v.push_back({a[i],a[i+1]});
    }

    n = v.size();
    ll tot = 0;

    for (int i=0; i<n; i++) {
	auto p = v[i];
	ll from = p.first;
	ll to = p.second;
	ll dist = (to-from+m)%m;
	tot += dist;
	ev[from].push_back({0,i});
	ev[to].push_back({1,i});
	//0: open, 1: close
    }

    ll best = tot;

    set<ll> active;//ids
    ll saving = 0;
    for (int i=0; i<m*2; i++) {
	saving += (ll)active.size();
	ll cur = tot - saving + (ll)active.size();

	best = min(best, cur);
	
	for (auto p: ev[i%m]) {
	    int id = p.second;
	    if (p.first == 0) {
		active.insert(id);
	    } else if (p.first == 1) {
		if (active.count(id)) {
		    ll from = v[id].first; ll to = v[id].second;
		    ll dist = (to-from+m)%m;
		    saving -= dist;
		    active.erase(id);
		}
	    }
	}
    }

    out(best);

    return 0;
}
