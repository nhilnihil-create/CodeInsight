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
  string s, t;
  cin >> s >> t;
  vector<int> sa(s.size()+1, 0);
  vector<int> ta(t.size()+1, 0);
  rep(i, s.size()){
    sa.at(i+1) = sa.at(i);
    if(s.at(i) == 'A') sa.at(i+1)++;
    else sa.at(i+1) += 2;
  }
  rep(i, t.size()){
    ta.at(i+1) = ta.at(i);
    if(t.at(i) == 'A') ta.at(i+1)++;
    else ta.at(i+1) += 2;
  }

  int q;
  cin >> q;
rep(_q, q){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--; c--;
  int gs = sa.at(b) - sa.at(a);
  int gt = ta.at(d) - ta.at(c);
  if(gs % 3 == gt % 3) cout << "YES" << endl;
  else cout << "NO" << endl;
}
  return 0;
}