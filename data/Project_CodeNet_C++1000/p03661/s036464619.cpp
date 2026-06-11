#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 200000000007;


  
signed main(){
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        a[i]+=a[i-1];    
    }
    int ans=abs(a[n-1]-2*a[0]);
    for(int i=1;i<n-1;i++)ans=min(abs(a[n-1]-2*a[i]),ans);
   
    
    cout<<ans;
    
    return 0;
}
