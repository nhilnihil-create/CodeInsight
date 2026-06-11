#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> hune(2, vector<ll>(n, 0));
    for(ll i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        if(min(a, b) == 1) hune[0][max(a, b) - 1] = 1;
        if(max(a, b) == n) hune[1][min(a, b) - 1] = 1;
    }
    bool f = false;
    for(ll i = 0; i < n; i++){
        if(hune[0][i] + hune[1][i] == 2){
            f = true;
            break;
        }
    }
    if(f) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
}