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
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll ans=0,p=0,q=0;
  bool is=false;
  rep(i,n-1){
    if(is==true && a.at(i)==a.at(i+1)){
      q=a.at(i);
      break;
    }
    if(a.at(i)==a.at(i+1)){
      is=true;
      i++;
      p=a.at(i);
    }
  }
  cout << p*q;
}
