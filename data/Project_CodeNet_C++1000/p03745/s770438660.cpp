#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        if (a[i] == a[i+1] && i < n-1){
            continue;
        }
        else if (a[i] < a[i+1]){
            while (a[i] <= a[i+1] && i < n-1){
                i++;
            }
        }
        else{
            while (a[i] >= a[i+1] && i < n-1){
                i++;
            }
        }
        //cout << i << endl;
        ans++;
    }

    cout << ans << endl;
}