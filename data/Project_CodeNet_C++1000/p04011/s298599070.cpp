#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i,n,k,x,y,ans=0;
    cin>>n>>k>>x>>y;
    for(i=1; i<=n; i++){
        if(i<=k){
            ans+=x;
        }else{
            ans+=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}