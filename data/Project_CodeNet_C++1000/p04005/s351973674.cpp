#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll mx,mint;
   ll ans=INFll;
   ll a,b,c;cin >>a>>b>>c;
   mx=a*b*((c-1)/2+1);
   mint=a*b*(c/2);
   ans=min(ans,mx-mint);
   swap(b,c);
    mx=a*b*((c-1)/2+1);
    mint=a*b*(c/2);
    ans=min(ans,mx-mint);
    swap(a,c);
    mx=a*b*((c-1)/2+1);
    mint=a*b*(c/2);
    ans=min(ans,mx-mint);
    cout <<ans <<endl;
   return 0;
}

