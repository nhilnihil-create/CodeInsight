#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A, B, v[100];
ll dp[100][100];

// return nCr
long long combination(long long n, long long r){
    r = (r < n - r) ? r : n - r;
    long long c = 1;
    for(long long k = 1; k <= r; ++k){
        c = c * n / k;
        n--;
    }
    return c;
}

signed main(){
    cin >> N >> A >> B;
    map<ll, ll> mp, np;
    REP(i, N){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v, v + N, greater<ll>());
    vector<ll> C;
    ll n = A, sum = accumulate(v, v + A, 0LL);
    ll max_n = A, max_sum = sum;
    FOR(i, A, B){
        n++;
        sum += v[i];
        if(sum * max_n > max_sum * n){
            max_n = n;
            max_sum = sum;
        }
    }
    n = sum = 0;
    REP(i, A){
        sum += v[i];
        n++;
        np[v[i]]++;
    }
    ll ans = 0;
    FOR(i, A, B + 1){
        if(sum * max_n == max_sum * n){
            ll c = 1;
            for(auto p : np){
                c *= combination(mp[p.first], p.second);
            }
            ans += c;
        }
        sum += v[i];
        n++;
        np[v[i]]++;
    }
    printf("%.9f\n", (double)max_sum / max_n);
    PRINT(ans);
    return 0;
}