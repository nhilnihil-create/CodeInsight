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
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll cnt=1;
  string s="";
  rep(i,n-1){
    if(a[i]!=a[i+1]){
      if(a[i]<a[i+1]){
        s="up";
        break;
      }
      else{
        s="down";
        break;
      }
    }
  }
  ll i=0;
  while(i<n-1){
    if(s==""){
      i+=1;
      while(i<n-1&&s==""){
        if(a[i]>a[i+1]){
          s="down";
        }
        else if(a[i]<a[i+1]){
          s="up";
        }
        if(s==""){
          i++;
        }
      }
    }
    if(a[i]<a[i+1]&&s=="down"){
      s="";
      cnt++;
    }
    else if(a[i]>a[i+1]&&s=="up"){
      s="";
      cnt++;
    }
    else{
      i++;
    }
  }
  cout << cnt << endl;
}