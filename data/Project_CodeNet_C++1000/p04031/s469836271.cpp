#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int ans = 1000000;
  int i = -100;
  while(i <= 100){
    int b = 0;
    REP(j,n){
      b += (a[j] - i) * (a[j] - i);
    }
    ans = min(ans,b);
    i++;
  }
  
  cout << ans << endl;
}
