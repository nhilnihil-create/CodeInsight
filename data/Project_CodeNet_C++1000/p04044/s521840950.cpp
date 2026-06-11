#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>
#define all(A) A.begin(), A.end()

int main() {
    ll n, l; cin >> n >> l;
    vs s(n);
    rep(i,n) cin >> s[i];

    sort(all(s));

    string ans = "";
    rep(i,n){
        ans += s[i];
    }

    cout << ans << endl;
}