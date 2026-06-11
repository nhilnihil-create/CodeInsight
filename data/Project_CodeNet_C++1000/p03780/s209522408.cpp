#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef pair<ll, ll> PLL;

ll N,K;
vector<ll> a;

// t番目のカードが必要なら真
bool f(ll t) {
    // dp[i][sum]: i番目のカードまでを使った時、値sumを作れるかどうか
    vector<vector<bool>> dp(N, vector<bool>(K+1, false));
    vector<ll> b;
    rep(i,0,N)
        if (i!=t)
            b.push_back(a[i]);

    dp[0][0]=true;
    rep(i,0,N-1){
        rep(s,0,K+1){
            if (!dp[i][s])
                continue;
            // b[i]を使う
            if(s+b[i]<=K)
                dp[i+1][s+b[i]] = true;
            // b[i]を使わない
            dp[i+1][s] = true;
        }
    }

    ll min_val = 1e15;
    rep(s,0,K+1){
        if (dp[N-1][s] && s+a[t]>=K){
            min_val = s+a[t];
            break;
        }
    }
    
    return min_val - a[t] < K;
}

signed main() {
    cin>>N>>K;
    a.resize(N);
    rep(i,0,N){
        cin>>a[i];
    }
    sort(begin(a),end(a));

    ll l=-1, r=N; // a_l以下は不要なカード、a_r以上は必要なカード
    while (l+1 < r){
        ll m=(l+r)/2;
        // printf("m=%d f(m)=%d\n", m, f(m));
        if (f(m))
            r=m;
        else
            l=m;
    }
    // printf("l=%d\n",l);
    cout<<l+1<<endl;
    return 0;
}
