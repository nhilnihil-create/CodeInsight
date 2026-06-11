#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

const ll MOD = 1000000007;

ll pow(ll x, ll y, ll z) {
    ll ret;
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % z;
    } else if (y % 2) {
        ret = pow(x, y/2, z);
        ret = ret * ret % z * x % z;
        return ret;
    } else {
        ret = pow(x, y/2, z);
        ret = ret * ret % z;
        return ret;
    }
}

int main(){
    ll N;
    ll i, j, k;

    cin >> N;
    
    vll Ts(N, 0); 
    vll As(N, 0);

    rep(i, N){
        cin >> Ts[i];
    }
    rep(i, N){
        cin >> As[i];
    }

    if (N == 1) {
        cout << (As[0] == Ts[0]) << endl;
        return 0;
    }


    ll m = max(Ts[0], As[0]);
    rep(i, N){
        if (m != max(Ts[i], As[i])) {
            cout << 0 << "\n";
            return 0;
        }
    }


    vll hs(N, 0);
    hs[0] = Ts[0];
    hs[N-1] = As[N-1];
    rep(i, N-1){
        if (Ts[i+1] > Ts[i]) {
            hs[i+1] = Ts[i+1];
        }
    }
    
    for (i = N-2; i >= 0; i--) {
        if (As[i] > As[i+1]) {
            if(hs[i] == 0){
                hs[i] = As[i];
            }
            else if (hs[i] != As[i]){
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    ll cummax = hs[0];
    rep(i, N-1){
        cummax = max(cummax, hs[i+1]);
        if (Ts[i+1] != cummax) {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    cummax = hs[N-1];
    for (i = N-2; i >= 0; i--) {
        cummax = max(cummax, hs[i]);
        if (cummax != As[i]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    ll prev = 0;
    ll ans = 1;
    i = 0;
    while (i < N) {
        while (i < N && hs[i] != 0) {
            i++;
        }
        prev = i - 1;
        while (i < N && hs[i] == 0) {
            i++;
        }
        if (i == N){
            break;
        }

        // cout << hs[i] << ',' << hs[prev] << endl;
        ans *= pow(min(hs[i], hs[prev]), i - prev - 1, MOD);
        // cout << ans << ' ';
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}