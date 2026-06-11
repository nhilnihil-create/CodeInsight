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
  string s;cin>>s;
  ll n=s.size();
  rep(i,n-1){
    if(s[i]==s[i+1]){
      cout<<i+1<<" "<<i+2<<endl;
      return 0;
    }
  }
  rep(i,n-2){
    if(s[i]==s[i+2]){
      cout<<i+1<<" "<<i+3<<endl;
      return 0;
    }
  }
  cout<<-1<<" "<<-1<<endl;
}