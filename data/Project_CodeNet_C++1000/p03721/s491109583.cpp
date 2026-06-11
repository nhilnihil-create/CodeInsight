#include <iostream>
#include <map>

using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;

  map<int, long long> m;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    m[a] += b;
  }

  for (const auto &p : m) {
    if (p.second >= K) {
      cout << p.first << endl;
      break;
    }
    K -= p.second;
  }
}
