#include <iostream>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int N; cin >> N;

  map<int, int> m;
  rep(i, N) {
    int A; cin >> A;
    ++m[A];
  }
  if (m.size() == 1) {
    if (m.begin()->first * 2 <= N || m.begin()->first == N-1)
      cout << "Yes\n";
    else
      cout << "No\n";
    return 0;
  }
  if (m.size() > 2) {
    cout << "No\n";
    return 0;
  }

  int a = max(m.begin()->first, m.rbegin()->first);
  int alone = m[a-1];

  if (m[a] + m[a-1] != N) {
    cout << "No\n";
    return 0;
  }
  if (alone < a && 2 * (a - alone) <= m[a])
    cout << "Yes\n";
  else
    cout << "No\n";


  return 0;
}
