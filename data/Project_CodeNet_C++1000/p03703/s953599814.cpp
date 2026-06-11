#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define FENWICK_NMAX 200010
struct fenwick_tree{
    ll N;
    ll bit[FENWICK_NMAX];
    fenwick_tree(ll n){
        N = n;
        for(ll x = 1; x <= N; x++){
            bit[x] = 0;
        }
    }
    void add(ll a, ll w){
        for(ll x = a; x <= N; x += x & -x){
            bit[x] += w;
        }
    }
    ll sum(ll a){
        ll ret = 0;
        for(ll x = a; x > 0; x -= x & -x){
            ret += bit[x];
        }
        return ret;
    }
};

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> s(N,0), a(N,0), b(N);
    ll ans = 0;
    rep(i, 0, N){
        cin >> a[i];
        if(i != 0) s[i] = a[i] + s[i-1];
        else s[i] = a[i];
        b[i] = s[i] - K * (i+1);
        if(b[i] >= 0) ans++;
    }
    auto c = b;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    fenwick_tree t(N+1);
    rep(i, 0, N){
        auto itr = lower_bound(c.begin(), c.end(), b[i]);
        ll tmp = itr - c.begin() + 1;
        ans += t.sum(tmp);
        t.add(tmp, 1);
    }
    cout << ans << endl;
    return 0;
}