#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
    int n,x;
    cin>>n>>x;
    int ans=0;
    ans+=n;
    int res=n-x;
    while(res){
        if(res%x==0){
            ans+=(2*res/x-1)*x;
            break;
        }
        else {
            ans+=(2*(res/x))*x;
            int tmp=res;
            res=x;
            x=tmp%x;
        }
    }
    cout<<ans<<endl;
}
