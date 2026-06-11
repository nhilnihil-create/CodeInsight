#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll k,t;cin >>k>>t;
   ll mx=0;
   ll sum=0;
    for (int i = 0; i < t; ++i) {
        ll a;cin >>a;
        mx=max(mx,a);
        sum+=a;
    }
//    cout <<sum <<" "<<mx<<endl;
    sum-=mx;
    mx-=sum;
    mx--;
    if(mx<0)cout <<0<<endl;
    else cout <<mx<<endl;
    return 0;
}

