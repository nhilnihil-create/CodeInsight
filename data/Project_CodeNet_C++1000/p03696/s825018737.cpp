#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin>>n;
  string s;
  cin>>s;
  vector<bool> z(n,true);
  rep(i,n){
    if(z[i]&&s[i]=='('){
      for(ll j=i+1;j<n;j++){
        if(z[j]&&s[j]==')'){
          z[i]=false;
          z[j]=false;
          break;
        }
      }
    }
    else if(z[i]&&s[i]==')'){
      for(ll j=i-1;j>=0;j--){
        if(z[j]&&s[j]=='('){
          z[i]=false;
          z[j]=false;
          break;
        }
      }
    }
  }
  ll count1=0,count2=0;
  rep(i,n){
    if(z[i]&&s[i]=='('){
      count1++;
    }
    else if(z[i]&&s[i]==')'){
      count2++;
    }
  }
  rep(i,count2){
  s.insert(0,"(");
  }
  rep(i,count1){
    s.pb(')');
  }
  print(s);
}
