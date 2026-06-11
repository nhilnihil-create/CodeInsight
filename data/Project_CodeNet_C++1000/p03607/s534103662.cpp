#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll tmp = a[0], count = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        if(tmp != a[i]){
            if(count%2 != 0) ans++;
            count = 0;
            tmp = a[i];
        }
        count++;
    }
    if(count%2 != 0) ans++;
    cout << ans << endl;
}