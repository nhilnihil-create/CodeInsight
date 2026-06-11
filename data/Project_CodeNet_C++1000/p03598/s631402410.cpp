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
  LL n,k,ans=0;
  cin >> n >> k;
  VLL x(n);
  REP(i,0,n){
    cin >> x.at(i);
    ans += min(x.at(i), k-x.at(i))*2;
  }
  
  
  
  cout << ans << endl;
  
  return 0;
}
