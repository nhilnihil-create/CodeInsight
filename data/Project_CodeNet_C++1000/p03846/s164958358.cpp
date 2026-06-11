#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = pow(10, 9) + 7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    bool f = true;
    int ite = 1, ans = 1, start = 0;
    if(a[0] == 0){
        start = 1;
        ite = 2;
    }
    for(int i = start; i < n; i += 2){
        if(ite == a[i]){
            ans *= 2;
            ans %= mod;
            ite += 2;
        }
        else{
            f = false;
            break;
        }
    }
    if(f) cout << ans << endl;
    else cout << 0 << endl;
}