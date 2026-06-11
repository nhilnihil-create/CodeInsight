#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(const vector<string> &a, const vector<string> &b, int si, int sj){
  rep(i, b.size()){
    rep(j, b.at(i).size()){
      if(a.at(i+si).at(j+sj) != b.at(i).at(j)) return false;
    }
  }
  return true;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  rep(i, n) cin >> a.at(i);
  vector<string> b(m);
  rep(i, m) cin >> b.at(i);
  rep(i, a.size()-b.size()+1){
    rep(j, a.at(i).size()-b.at(0).size()+1){
      if(fc(a, b, i, j) == true){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}