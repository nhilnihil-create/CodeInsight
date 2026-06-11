#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main () {
  int N, M;
  cin >> N >> M;
  set<int> S, T;
  int a, b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    if (a==1) {
      S.insert(b);
    }
    if (b==N) {
      T.insert(a);
    }
  }
  
  string ans="IMPOSSIBLE";
  for (int i=1; i<=N; i++) {
    if (S.count(i) && T.count(i)) {
      ans="POSSIBLE";
      break;
    }
  }
  cout << ans << endl;
}
 