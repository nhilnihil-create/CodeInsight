#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        ll sa = a[i] + a[i + 1] - x;
        if(sa > 0){
            a[i + 1] = a[i + 1] - sa;
            if(a[i + 1] < 0){
                a[i] += a[i + 1];
                a[i + 1] = 0;
            }
            ans += sa;
        }
    }
    cout << ans << endl;
}