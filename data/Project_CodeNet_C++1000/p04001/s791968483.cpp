#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using VPI = vector<PII>;
using VPL = vector<PLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  string s;
  cin >> s;
  int n = s.size();
  VLL a(n);
  REP(i,0,n){
    a[i] = s[i] - '0';
  }
  
  LL ans = 0;
  REP(i,0,1<<(n-1)){
    LL cnt = a[0];
    RREP(j,n-2,0){
      if(((i >> j) & 1) == 0){
        cnt *= 10;
        cnt += a[n-j-1];
      }
      else{
        ans += cnt;
        cnt = a[n-j-1];
      }
    }
    ans += cnt;
  }
        
  cout << ans << endl;
  
  return 0;
}
