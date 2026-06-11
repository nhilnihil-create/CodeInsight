#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll nCr(ll n, ll r){
    ll a = 1;
    ll b = 1;
    rep(i, r){
        a *= n-i;
        b *= i+1;
    }
    return a/b;
}

int main()
{
    ll N, P;
    cin >> N >> P;
    vector<ll> A(N);
    ll even = 0;
    ll odd = 0;
    rep(i, N){
        cin >> A[i];
        if (A[i] % 2 == 0){
            even++;
        }else{
            odd++;
        }
    }

    if(even == N){
        if (P == 0){
            ll ans = 1;
            rep(i, N){
                ans *= 2;
            }
            cout << ans << endl;
        }else{
            puts("0");
        }
        return 0;
    }

    ll ans = 1;
    rep(i, N-1){
        ans *= 2;
    }
    cout << ans << endl;


    return 0;
}
