#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)

int main(){
  LL n,ans=0;
  cin >> n;
  VLL l(n),r(n);
  REP(i,0,n){
    cin >> l.at(i) >> r.at(i);
    ans += (r.at(i) - l.at(i)) + 1;
  }
  
  cout << ans << endl;
  
  return 0;
}
