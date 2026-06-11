#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans,div;
    div=1000000000+7;
    cin>>n;
    ans=1;
    for(long long i=1;i<=n;i++){
        ans*=i;
        if(ans>div){
            ans%=div;
        }
    }
    cout<<ans<<endl;
}