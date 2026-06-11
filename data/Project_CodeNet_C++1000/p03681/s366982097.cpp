#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int INF = 1e9;
const ll MOD = 1e9 + 7;  

int main(){
    int N,M;
    cin >> N >> M;
    ll ans = 1;
    if(abs(N-M) >= 2){
        ans = 0;
    }
    else if(N == M){
        for(ll l = N; l >= 1; l--){
            ans = ans * l % MOD;
            ans = ans * l % MOD;
        }
        ans = ans * 2 % MOD;
    }
    else if(abs(N-M) == 1){
        for(ll l = N; l >= 1; l--){
            ans = ans * l % MOD;
        }
        for(ll l = M; l >= 1; l--){
            ans = ans * l % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

