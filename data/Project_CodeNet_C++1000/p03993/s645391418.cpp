#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  int N, cnt = 0;
  cin >> N;
  vector<int> a(N), c(N, 0);
  REP(i, N) cin >> a[i];
  for (int i = 0; i < N;i++){
    if(c[i]!=0)
      continue;
    if (a[a[i] - 1] == i +
     1) {
      cnt++;
      c[a[i] - 1] = 1;
    }
  }
  cout << cnt << endl;

  return 0;
}