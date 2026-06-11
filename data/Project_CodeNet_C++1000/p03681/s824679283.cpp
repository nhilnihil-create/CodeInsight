#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mod=1000000007;
    int diff=abs(n-m);
    if(diff>1){
        cout<<0<<endl;
    }else{
        ll ntemp=1;
        ll mtemp=1;
        for(int i=1;i<=n;i++){
            ntemp*=i;
            ntemp%=mod;
        }
        for(int i=1;i<=m;i++){
            mtemp*=i;
            mtemp%=mod;
        }
        ll ans=ntemp*mtemp%mod;
        if(diff==0){
            cout<<ans*2%mod<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
