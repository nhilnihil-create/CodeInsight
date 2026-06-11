#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c,aa = 0;
  cin >> a >> b >> c;
  aa = a;
  bool can = false;
  REP(i,b*2){
    if(aa % b == c) can = true;
    aa += a;
  }
  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;
}
