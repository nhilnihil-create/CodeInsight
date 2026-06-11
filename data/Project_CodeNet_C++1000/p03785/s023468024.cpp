#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n,c,k;
  cin >> n >> c >> k;
  vl t(n);
  rep(i,n){
    cin >> t[i];
  }
  sort(t.begin(),t.end());
  ll bus=1;
  ll start=t[0];
  ll i=0;
  ll cnt=0;
  while(i<n){
    if(start+k>=t[i]&&cnt<c){
      cnt++;
    }
    else{
      start=t[i];
      cnt=1;
      bus++;
    }
    i++;
  }
  cout << bus << endl;
}