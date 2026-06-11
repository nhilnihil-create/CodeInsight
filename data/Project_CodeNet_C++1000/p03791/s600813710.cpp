#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll mod = 1e9+7;
    ll ans = 1;
    ll now = 1;
    for(int i=0;i<n;i++){
        if(i!=n-1 && a[i] < 2*now-1){
            ans *= now;
            ans %= mod;
        }
        else if(i!=n-1) now++;
    }
    
    for(int i=1;i<=now;i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;;

}