#include <bits/stdc++.h>

#define ll long long
#define nl '\n'
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define fori(i, a, b) for(ll i = a; i < b; ++i)

using namespace std;

int main(){

    #ifdef LOCAL  
        freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> v;

    ll n; cin >> n;
    ll l; cin >> l;

    forn(i, n){
        string s; cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for(auto x : v) cout << x;
    cout << nl;

    return 0;
}	
    