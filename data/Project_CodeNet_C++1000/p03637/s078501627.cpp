#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  string ans="No";
  ll p=0,q=0;
  bool is=false;
  rep(i,n){
    if(a.at(i)%4==0){
      p+=2;
      is=true;
    }else if(a.at(i)%2==0){
      q++;
    }
  }
  if(is &&n%2==1){
    p++;
  }
  if(p+q>=n){
    ans="Yes";
  }
  cout << ans;
}