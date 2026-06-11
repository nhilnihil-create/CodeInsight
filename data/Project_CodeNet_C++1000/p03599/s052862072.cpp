#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<bool>dpw(31,false);
  dpw[0] = true;
  rep(i,0,31){
    if(!dpw[i]) continue;
    if(i+a <= 30) dpw[i+a] = true;
    if(i+b <= 30) dpw[i+b] = true;
  }
  vector<int>w;
  rep(i,0,31) if(dpw[i] && i != 0) w.push_back(i*100);
  
  vector<bool>dps(3000+1,false);
  dps[0] = true;
  rep(i,0,dps.size()){
    if(!dps[i]) continue;
    if(i+c < dps.size()) dps[i+c] = true;
    if(i+d < dps.size()) dps[i+d] = true;
  }
  vector<int>s;
  rep(i,0,dps.size()) if(dps[i]) s.push_back(i);
  
  int as,ss;
  double den = 0;
  rep(i,0,w.size()){
    rep(j,0,s.size()){
      double wa = w[i],su = s[j];
      if(100*s[j] <= e*w[i] && w[i]+s[j] <= f && su/(wa+su) >= den){
        as = w[i]+s[j];
        ss = s[j];
        den = su/(wa+su);
      }
    }
  }
  cout << as << " " << ss << endl;
}