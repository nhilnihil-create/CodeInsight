#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll x;
    cin>>x;
    ll ans=x/11;
    ans*=2;
    if(x%11>0 && x%11<7)ans+=1;
    else if(x%11>=7)ans+=2;
    cout<<ans<<endl;
}