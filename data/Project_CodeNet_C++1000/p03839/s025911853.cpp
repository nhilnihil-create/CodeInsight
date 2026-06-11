#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N, K;
    cin >> N >> K;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll sum[N-K+1], mx[N-K+1], ans[N-K+1];
    ll zero = 0, M = 0;
    sum[0] = 0, mx[0] = 0;
    rep(i, N) M += max(zero, a[i]);
    rep(i, K){
        sum[0] += a[i];
        mx[0] += max(zero, a[i]);
    }
    rep(i, N-K){
        sum[i+1] = sum[i] + a[i+K]-a[i];
        mx[i+1] = mx[i] + max(zero,a[i+K]) - max(zero,a[i]);
    }
    ll res = 0;
    rep(i, N-K+1){
        ans[i] = M-mx[i] + max(zero, sum[i]);
        res = max(res, ans[i]);
    }
    cout << res << endl;
}