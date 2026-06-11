#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    vector<ll> data(n), left(n+1,0), right(n+1,0);
    rep(i,n) cin >> data[i];
    rep(i,n) left[i+1] = left[i] + max(0ll,data[i]);
    rep(i,n) right[i+1] = right[i] + max(0ll,data[n-1-i]);

    ll count = 0; rep(i,k) count += data[i];
    ll ans = max(0ll,count) + left[0] + right[n-k];
    rep(i, n-k){
        count += data[k+i];
        count -= data[i];
        chmax(ans, max(0ll,count) + left[1+i] + right[n-k-1-i]);
    }
    cout << ans << endl;
}