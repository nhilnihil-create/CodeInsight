#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,x;
    cin>>n>>x;
    
    ll ans = 0;
    
    vector<ll> a(n);
    cin >> a[0];
    ll diff = 0;
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i-1]+a[i]>x){
            diff = a[i-1]+a[i] - x;
            ans += diff;
            if(a[i]<diff)a[i]=0;
            else a[i] -= diff;
        }
    }
    
    cout << ans << endl;
    
}