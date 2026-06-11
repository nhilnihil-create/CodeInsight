#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  vector<string> s(3);
  rep(i, 3) cin >> s.at(i);
  vector<int> index(3, 0);
  int now = 0;
  while(1){
    if(index.at(now) == s.at(now).size()){
      char o = now + 'A';
      cout << o << endl;
      return 0;
    }
    char c = s.at(now).at(index.at(now));
    index.at(now)++;
    now = c - 'a';
  }
  return 0;
}