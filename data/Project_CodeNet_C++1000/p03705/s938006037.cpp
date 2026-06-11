#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    ll a,b;cin >>a>>b;
    ll mint=a*(n-1)+b;
    ll mx=b*(n-1)+a;
    ll ans=mx-mint+1;
    if(ans<0)ans=0;
    cout <<ans <<endl;
    return 0;
}

