#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,MOD=1e9+7,ans=1;
stack<ll> sta;
int main(void){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a;
        if(2*(sta.size()+1)-1>a){
            ans*=sta.size()+1;
            ans%=MOD;
        }
        else sta.push(a);
    }
    for(ll i=1;i<=sta.size();i++){
        ans*=i;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
