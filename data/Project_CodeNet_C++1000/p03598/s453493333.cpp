#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
   ll N,K;
   cin>>N>>K;
   ll ans=0;
   for(ll i=0;i<N;i++) {
       ll x;
       cin>>x;
       ans+=min(x,K-x);
   }
   cout<<2*ans<<endl;


   }
