#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

// nCa
ll combinationWithoutMod(ll n, ll k){
    ll v[51][51];
    rep(i,n+1){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    repi(i,n+1){
        repi(j,i){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v[n][k];
}

void Main()
{
    ll n, A, B;
    cin >> n >> A >> B;

    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    
    sort(all(v));
    reverse(all(v));

    ll sum = 0;
    rep(i, A) {
        sum += v[i];
    }
    ld avg = (ld)sum / A;
    printf("%.6Lf\n", avg);

    ll minVal = v[A - 1];
    ll offset = -1;
    ll len = 0;
    rep(i, n) {
        if (minVal == v[i]) {
            if (offset < 0) offset = i; 
            len++;
        }
    }

    // 上位が全部minValだった場合、A+1個とってもよい
    ll res = 0;
    if (offset == 0) {
        for (ll i = A; i <= B; i++) {
            res += combinationWithoutMod(len, i);
        }
    }
    else {
        res = combinationWithoutMod(len, A - offset);
    }

    put(res);

}
signed main(){ Main();return 0;}