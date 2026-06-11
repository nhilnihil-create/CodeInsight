#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD=1000000000 + 7;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main(){
    cout << setprecision(10);

    int N;
    cin >> N;
    ll h_max_a[N], h_min_a[N];
    ll h_max_b[N], h_min_b[N];
    ll h_max[N], h_min[N];

    ll now_max_h = 0;
    for(int i = 0; i < N; i++){
        ll h;
        cin >> h;
        if(now_max_h < h){
            h_max_a[i] = h;
            h_min_a[i] = h;
            now_max_h = h;
        } else { 
            h_max_a[i] = now_max_h;
            h_min_a[i] = 1;
        }
    }
    vector<ll> b_input(N);
    for(int i = 0; i < N; i++){
        cin >> b_input.at(i);
    }
    reverse(b_input.begin(), b_input.end());
    
    now_max_h = 0;
    for(int i = 0; i < N; i++){
        ll h;
        h = b_input[i];
        if(now_max_h < h){
            h_max_b[N-1-i] = h;
            h_min_b[N-1-i] = h;
            now_max_h = h;
        } else { 
            h_max_b[N-1-i] = now_max_h;
            h_min_b[N-1-i] = 1;
        }
    }

    ll ans = 1;
    bool flg = true;
    for(int i = 0; i < N; i++){
        h_max[i] = min(h_max_a[i], h_max_b[i]);
        h_min[i] = max(h_min_a[i], h_min_b[i]);
        if(h_max[i] < h_min[i]){
            flg = false;
            break;
        }
    }

    if(flg){
        for(int i = 0; i < N; i++){
            ans *= h_max[i] - h_min[i] + 1;
            ans %= MOD;
        }
    } else { 
        ans = 0;
    }
    cout << ans << endl;


}
