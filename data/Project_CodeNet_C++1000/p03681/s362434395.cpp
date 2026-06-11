#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    long long mod=1e9+7;
    long long ans=1;
    if(abs(n-m)>=2){
        cout<<0<<endl;
    }else if(abs(n-m)==1){
        for(int i=1;i<=m;i++){
            ans*=i;
            ans%=mod;
        }
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<endl;
    }else if(abs(n-m)==0){
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        ans=2*ans*ans;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}