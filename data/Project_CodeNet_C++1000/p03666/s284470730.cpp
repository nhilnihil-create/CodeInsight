//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  rep(i,n){
    if(-d*i+c*(n-1-i)<=b-a&&b-a<=-c*i+d*(n-1-i)){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}