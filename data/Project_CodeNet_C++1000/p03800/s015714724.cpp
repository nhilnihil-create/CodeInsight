#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fichk(vector<bool> &f, string s){
  if((s.at(0) == 'x') ^ f.at(0)){
    return f.at(1) == f.at(f.size()-2);
  }else{
    return f.at(1) != f.at(f.size()-2);
  }
}

bool fc(vector<bool> &f, string s){
  int n = s.size();
  rep2(i, 1, n){
    bool c = (s.at(i) == 'x');
    if((f.at(i) ^ c) == true){
      f.at(i+1) = f.at(i-1);
    }else{
      f.at(i+1) = !f.at(i-1);
    }
  }
  // rep(i, f.size()) cerr << f.at(i);
  // cerr << endl;
  if(f.at(0) == f.at(n) && fichk(f, s)) return true;
  return false;
}

void ap(vector<bool> &f){
  rep(i, f.size()-1){
    char o;
    if(f.at(i) == true) o = 'S';
    else o = 'W';
    cout << o;
  }
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> f(n+1);
  f.at(0) = true; f.at(1) = true;
  if(fc(f, s)){
    ap(f);
    return 0;
  }
  f.at(0) = true; f.at(1) = false;
  if(fc(f, s)){
    ap(f);
    return 0;
  }
  f.at(0) = false; f.at(1) = true;
  if(fc(f, s)){
    ap(f);
    return 0;
  }
  f.at(0) = false; f.at(1) = false;
  if(fc(f, s)){
    ap(f);
    return 0;
  }
  cout << -1 << endl;
  return 0;
}