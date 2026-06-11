#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m = 0;
  cin >> n;
  vector<bool> cnt(13,false);
  int ans = 0;
  REP(i,n){
    int a;
    cin >> a;
    int b = a/400;
    cnt[b] = true;
    if(b >= 8){
      m++;
    }
  }
  REP(i,8){
    if(cnt[i] == true) ans++;
  }
  if(n == m){
    cout << 1 << " ";
  }
  else{
    cout << ans << " ";
  }
  REP(i,m){
    ans++;
  }
  cout << ans << endl;
}
