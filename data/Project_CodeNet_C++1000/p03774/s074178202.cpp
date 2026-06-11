#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
const ll Mod = 1000000007;
ll INF = Mod * 100LL;
int main() {
  int N,M;
  cin >> N >> M;
  ll a[N],b[N],c[M],d[M];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> c[i] >> d[i];
  }
  int ind = -1;
  ll mi = INF;
  for (int i = 0; i < N; i++) {
    int ind = -1;
    ll mi = INF;
    for (int j = 0; j < M; j++) {
      ll res = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (res < mi) {
        mi = res;
        ind = j;
      }
    }
    cout << ind + 1 << endl;
  }
  return 0;
}