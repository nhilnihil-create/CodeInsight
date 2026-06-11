#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = pow(10, 9) + 7;

int main(){
    ll n;
    cin >> n;
    vector<int> sosu(n + 1, 0);
    ll ans = 1;
    for(int i = 2; i <= n; i++){
        bool f = true;
        for(int j = 2; j < i; j++){
            if(i%j == 0) f = false;
        }
        if(f) sosu[i] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(sosu[i] == 1){
            ll c = 0, waru = i;
            while(waru <= n){
                c += n/waru;
                waru *= i;
            }
            ans *= (c + 1)%mod;
            ans %= mod;
        }
    }
    cout << ans%mod << endl;
}