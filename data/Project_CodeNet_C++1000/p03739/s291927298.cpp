#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  vector<ll> s(n+1,0);
  rep(i,n)s[i+1] = s[i]+v[i];
  ll res = 0,res_ = 0;
  ll ch = 0,ch_ = 0;
  bool pre = 0,pre_ = 1;
  rep(i,n){
    if(pre){
      if(s[i+1]+ch >= 0){
        res += s[i+1]+ch+1;
        ch -= s[i+1]+ch+1;
      }
      pre = false;
    }else{
      if(s[i+1]+ch <= 0){
        res += abs(s[i+1]+ch)+1;
        ch += abs(s[i+1]+ch)+1;
      }
      pre = true;
    }
    if(pre_){
      if(s[i+1]+ch_ >= 0){
        res_ += s[i+1]+ch_+1;
        ch_ -= s[i+1]+ch_+1;
      }
      pre_ = false;
    }else{
      if(s[i+1]+ch_ <= 0){
        res_ += abs(s[i+1]+ch_)+1;
        ch_ += abs(s[i+1]+ch_)+1;
      }
      pre_ = true;
    }
  }
  cout << min(res,res_) << endl;
  
  






  return 0;
}