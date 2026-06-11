#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;

int main(){
  ll n,m; cin >> n >> m;
  vector<string> a(n);
  rep(i,n){
    string c; cin >> c; a[i]=c;
  }
  if(debug){
    rep(i,n){
      cout << a[i] << endl;
    }
  }
  vector<string> b(m);
  rep(i,m){
    string s; cin >> s; b[i]=s;
  }
  if(debug){
    rep(i,m){
      cout << b[i] << endl;
    }
  }
  auto isIncluded = [&](ll si, ll sj)->bool{
    ll ei = si+m-1; ll ej= sj+m-1;
    if(ei>=n||ej>=n) return false;
    for(ll i=si; i<=ei; i++){
      for(ll j=sj; j<=ej; j++){
        if(a[i][j]!=b[i-si][j-sj]) return false;
      }
    }
    return true;
  };
  rep(i,n)rep(j,n){
    if(isIncluded(i,j)){
      cout << yes;
      return 0;
    }
  }
  cout << no;
  return 0;
}