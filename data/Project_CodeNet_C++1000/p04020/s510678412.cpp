#include <bits/stdc++.h>
using namespace std;
const int m=1e5+1;
int  a[m];
main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    long long ans=0ll;
    for(int i=n-1;i>=0;i--){
        ans+=a[i]/2;
        if(a[i]&1)
            if(i!=0&&a[i-1]){
                ++ans;
                --a[i-1];
                --a[i];
            }
    }   
    cout << ans << endl;
}