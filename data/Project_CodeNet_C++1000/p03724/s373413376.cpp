#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  int cnt[N];
  int a[M],b[M];
  for (int i = 0; i < N; i++) cnt[i] = 0;
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  bool can = true;
  for (int i = 0; i < N; i++) {
    if (cnt[i] % 2 != 0) {
      can = false;
    }
  }
  if (can) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}