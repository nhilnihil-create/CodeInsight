#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h)cin >> s[i];
  vector<int> v(26,0);
  rep(i,h)rep(j,w)v[s[i][j]-'a']++;
  int cnt = 0;
  if(h & 1)cnt++;
  if(w & 1)cnt++;
  if(cnt == 0){
    bool is = true;
    rep(i,26)if(v[i] % 4 != 0)is = false;
    if(is)cout << "Yes" << endl;
    else cout << "No" << endl;
  }else if(cnt == 1){
    int cnt_ = 0;
    rep(i,26){
      if((v[i] % 4) == 2)cnt_ += 2;
      else if(v[i] & 1)cnt_ = -(1 << 30);
    }
    if(cnt_ < 0){
      cout << "No" << endl;
    }else if(h & 1){
      if(cnt_ <= w)cout << "Yes" << endl;
      else cout << "No" << endl;
    }else{
      if(cnt_ <= h)cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }else{
    int cnt_ = 0,cnt__ = 0;
    rep(i,26){
      if((v[i] % 4) == 2)cnt_ += 2;
      else if(v[i] & 1)cnt__++;
    }
    if(cnt__ != 1){
      cout << "No" << endl;
    }else{
      if(h+w-2 >= cnt_)cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

  
  




  return 0;
}