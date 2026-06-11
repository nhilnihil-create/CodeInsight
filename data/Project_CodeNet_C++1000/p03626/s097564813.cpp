#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
  ll n,ans=1;cin>>n;
  string s,t;cin>>s>>t;

  for(int i=0;i < n;i++)
  {
    if(i==0){
      if(s[i]==t[i])ans*=3;
      else {ans*=6;i++;}
    }else{

      if(s[i]==t[i]){
        if(s[i-1]==t[i-1])ans*=2;
      }else {
        if(s[i-1]==t[i-1]){
          ans*=2;
        }else{
          ans*=3;
        }
        i++;
      }

    }
    ans%=mod;
  }
  cout<<ans<<endl;
}


