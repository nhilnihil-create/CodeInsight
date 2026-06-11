#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
void cxxio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back

vvi opp;

int f(int v) {
    vi xs;
    for (int u:opp[v]) xs.pb(f(u));
    sort(all(xs));
    reverse(all(xs));
    int ans=0;
    forn(i, xs.size()) {
        ans=max(ans, i+1+xs[i]);
    }
    return ans;
}

int main() {
    cxxio();
    int n;
    cin>>n;
    opp.resize(n);
    for (int i=1, x; i<n; i++) {
        cin>>x, x--;
        opp[x].pb(i);
    }
    cout<<f(0)<<'\n';
}
