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

    ll a, b, c; cin >> a >> b >> c;

    ll an[11] = {0};
    an[a]++; an[b]++; an[c]++;

    if(an[5] == 2 && an[7] == 1) cout << "YES" << nl;
    else cout << "NO" << nl;
    return 0;
}	
    