//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

vector<ll>prime_factorize(ll n){
    vector<ll>res;
    for(ll p = 2;p <= sqrt(n);p++){
        ll cnt=0;
      if (n%p != 0) continue;
      while(n % p == 0){
        n /= p;
        //res.push_back(p);
        cnt++;
      }
      res.push_back(cnt);
    }
    if (n != 1) res.push_back(1);
    return res;
}

int main(){
    ll n; cin>>n;
    map<ll,ll>mp;
    for(ll i=2;i<=n;i++){
        ll a=i;
        for(ll j=2;j<=1000;j++){
            if(a%j!=0)continue;
            while(a%j==0){
                a/=j;
                mp[j]++;
            }
            if(a==1)break;
        }
    }
    ll ans=1;
    for(auto p:mp){
        ans*=p.second+1;
        ans%=mod;
    }
    cout<<ans<<endl;
}

















































