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
struct edge{ll to,cost;};

const ll MAXN=100000;
ll n;
string s;
vector<char> c(MAXN);

bool check(char c0,char c1){
  bool B=true;
  c[0]=c0;
  c[1]=c1;
  FOR(i,2,n){
    if(s[i-1]=='o'&&c[i-1]=='S'||s[i-1]=='x'&&c[i-1]=='W'){
      c[i]=c[i-2];
    }
    else{
      if(c[i-2]=='W'){
        c[i]='S';
      }
      else{
        c[i]='W';
      }
    }
  }
  ll cnt=0;
  if(c[0]=='W'){
    cnt++;
  }
  if(s[0]=='x'){
    cnt++;
  }
  if(c[n-1]!=c[1]){
    cnt++;
  }
  if(cnt%2!=0){
    B=false;
  }
  if(c[n-1]=='W'){
    cnt++;
  }
  if(s[n-1]=='x'){
    cnt++;
  }
  if(c[n-2]!=c[0]){
    cnt++;
  }
  if(cnt%2!=0){
    B=false;
  }
  return B;
}
  
int main() {
  cin >> n >> s;
  if(check('S','S')){
    rep(i,n){
      cout << c[i];
    }
  }
  else if(check('S','W')){
    rep(i,n){
      cout << c[i];
    }
  }
  else if(check('W','S')){
    rep(i,n){
      cout << c[i];
    }
  }
  else if(check('W','W')){
    rep(i,n){
      cout << c[i];
    }
  }
  else{
    cout << -1;
  }
}