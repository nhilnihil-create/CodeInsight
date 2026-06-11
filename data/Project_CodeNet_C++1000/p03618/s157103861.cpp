#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string A;
    cin >> A;
    ll N = A.size();
    map<char, int> mp;
    rep(i, 26){
        mp[alpha[i]] = i;
    }
    ll cnt[26];
    fill_n(cnt, 26, 0);
    rep(i, N){
        cnt[mp[A[i]]]++;
    }
    ll ans = 1 + N*(N-1)/2;
    rep(i, 26){
        ans -= cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans << endl;
}