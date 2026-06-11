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
    for(int i=0;i<n;i++) cin>>a[i];    
    ll ans = 0;
    ll now = 1;
    for(int i=0;i<n;i++){
        if(now == a[i]){
            now++;
            continue;
        }
        ans += (a[i]-1LL) / now;
        if(now==1)now++;
    }
    cout << ans << endl;
}