#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    ll n,p;cin >>n>>p;
    ll co1=0,co0=0;
    for (int i = 0; i < n; ++i) {
        ll a;cin >>a;
        if(a%2==0)co0++;
        else co1++;
    }
    ll ans=0;
    if(co1==0){
        if(p==0) {
            ans = pow(2, n);
        }
    }
    else {
        ans=pow(2,n-1);
    }
    cout <<ans<<endl;
    return 0;
}