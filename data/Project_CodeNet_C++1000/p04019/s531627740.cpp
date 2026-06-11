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
  string s;
  cin >> s;
  ll k=s.size();
  ll a=0,b=0,c=0,d=0;
  rep(i,k){
    if(s[i]=='S'){
      a++;
    }
    else if(s[i]=='N'){
      b++;
    }
    else if(s[i]=='W'){
      c++;
    }
    else
      d++;
  }
  if(a*b==0&&max(a,b)!=0){
    cout << "No" << endl;
  }
  else if(c*d==0&&max(c,d)!=0){
    cout << "No" << endl;
  }
  else
    cout << "Yes" << endl;
}