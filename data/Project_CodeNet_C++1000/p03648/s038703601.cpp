#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    ll n = 50; ll k; cin >> k;
    vector<ll> ans;
    ll r = k % n;
    ll q = k / n;
    rep(i, n-r) ans.push_back(49-r);
    rep(i,r) ans.push_back(50);
    rep(i,n) ans[i] += q;
    cout << n << endl;
    rep(i,n) printf("%lld%c", ans[i], i == n-1 ? '\n' : ' ');
}