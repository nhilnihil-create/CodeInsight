#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  ll n;cin>>n;
  vector<ll>a(n);
  vector<ll>b(n);
    for (int i = 0; i <n; ++i) {
        cin>>a[i]>>b[i];
    }
    reverse(all(a));
    reverse(all(b));
    ll ans=0;
    ll now=0;
    for (int i = 0; i < n; ++i) {
        a[i]+=now;
        a[i]%=b[i];
        if(a[i]!=0){
            ans+=b[i]-a[i];
            now+=b[i]-a[i];
        }
    }
    cout <<ans<<endl;
  return 0;
}

