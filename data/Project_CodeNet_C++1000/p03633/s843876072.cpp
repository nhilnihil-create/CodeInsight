#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,t,ans;
    cin>>n>>t;
    ans=t;
    for(int i=0;i<n-1;i++){
        cin>>t;
        ans=lcm(ans,t);
    }
    cout<<ans<<endl;
    return(0); 
}
