#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;



int main() {
  int n,m;
  cin >> n;
  vector<int> t(n);
  REP(i,n){
    cin >> t[i];
  }
 
  cin >> m;
  vector<int> p(m);
  vector<int> x(m);
  REP(i,m){
    cin >> p[i] >> x[i];
    p[i] -= 1;
  }
  
  
  vector<int> tt(n);
  REP(i,n){
    tt[i] = t[i];
  }
  REP(i,m){
    t[(p[i])] = x[i];
    int ans = 0;
      REP(j,n){
        ans += t[j];
      }
    cout << ans << endl;
    t[p[i]] = tt[p[i]];
  }
  
}