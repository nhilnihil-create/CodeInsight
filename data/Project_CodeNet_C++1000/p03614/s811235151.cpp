#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main() {
  i64 N;
  cin >> N;
  vector<i64> p(N);
  for(int i = 0;i < N;i++) { cin >> p[i]; p[i]--; }
  i64 ans = 0;
  for(int i = 0;i + 1 < N;i++) {
    if(p[i] == i) {
      swap(p[i], p[i + 1]);
      ans++;
    }
  }
  cout << ans + !!(p[N - 1] == N - 1) << endl;
}
