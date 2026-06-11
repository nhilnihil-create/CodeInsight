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

int main(){
  int h, w;
  cin >> h >> w;
  map<char, int> mp;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      mp[s.at(j)]++;
    }
  }

  int p4 = 0, p2 = 0, p1 = 0;
  for(auto p : mp){
    p4 += p.second/4;
    p.second %= 4;
    p2 += p.second/2;
    p.second %= 2;
    p1 += p.second;
  }

  bool e = false;
  if(h % 2 == 1 && w % 2 == 1){
    if(p1 != 1) e = true;
  }else{
    if(p1 != 0) e = true;
  }
  int h2 = h/2, w2 = w/2;
  if(p4 < h2*w2) e = true;
  if(e == false) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}