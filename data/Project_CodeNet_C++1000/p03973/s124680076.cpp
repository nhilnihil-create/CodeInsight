#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i]; a[i]--;
    }
    ll ans = a[0];
    int now = 2;
    for(int i=1;i<n;i++){
        if(a[i]+1==now) now++;
        ans += a[i]/now;
        
    }
    cout << ans << endl;
}