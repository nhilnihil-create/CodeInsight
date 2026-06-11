#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll n;
    cin>>n;
    ll temp=0;
    ll limit=sqrt(n);
    for(ll i=1;i<=limit;i++){
          if(n%i==0)temp=i;
    }
    ll temptwo=n/temp;
    ll ans=0;
    while(temptwo>0){
        temptwo/=10;
        ans+=1;
    }
    cout<<ans<<endl;
}