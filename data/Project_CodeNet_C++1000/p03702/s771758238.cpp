#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
int N, A, B;
int h[100010], d[100010];

bool ensure(int p) {
  if(p < 0) return false;
  for(int i = 0; i < N; ++i) {
    d[i] = h[i] - p * B;
  }
  int ret = 0;
  for(int i = 0; i < N; ++i) {
    if(d[i] >= 0) ret += (d[i] + (A-B) - 1) / (A - B);
  }
  if(ret > p) return false;
  return true;
}

signed main() {
  cin >> N >> A >> B;
  for(int i = 0; i < N; ++i) {
    cin >> h[i];
  }
  int l = -1, r = 1e9+7, m;
  while(true) {
    m = (l + r) / 2;
    bool p1 = ensure(m-1), p2 = ensure(m);
    if(!p1 && p2) {
      cout << m << endl;
      break;
    }
    if(p1) {
      r = m;
    } else {
      l = m;
    }
  }
  return 0;
}
