#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,x;cin >>n>>x;
    ll ans=0;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        ll sum=a[i]+a[i+1];
        if(sum<=x)continue;
        if(a[i+1]<sum-x){
            ans+=a[i+1];
            ll c=sum-x;
            c-=a[i+1];
            a[i+1]=0;
            a[i]-=c;
            ans+=c;
        }
        else {
            a[i+1]-=sum-x;
            ans+=sum-x;
        }
    }
    cout <<ans <<endl;
    return 0;
}
