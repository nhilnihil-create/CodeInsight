#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define ford(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define szof(x) ((int)(x).size())
#define rsz resize
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
#define INFL (long long)1e18
#define re return
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector <int> >
#define VVLL vector<vector <long long> >
#define VLL vector <long long>
#define mt make_tuple

using namespace std;

int n,a,b;
vector <int> h;
int delta;

bool f(int m) {
    vector <ll> c;
    ll otn = m*1ll*b;
    for (auto elem : h) {
        if (elem - otn > 0) {
            c.pb(elem - otn);
        }
    }
    ll cur = 0;
    for (auto elem : c) {
        cur += ceil(1.00*elem/delta);
      //  cout << elem << " " << delta << '\n';
    }
   // cout << m << " " << cur << '\n';
    return cur <= m;
}

int main() {
    fastIO;
    cin >> n >> a >> b;
    h.rsz(n);
    for (auto & x : h) {
        cin >> x;
    }
    delta = a-b;
    ll l = -1;
    ll r = 1e9+1;
    while(r-l > 1) {
        int m = (l+r)/2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";
	return 0;
}
