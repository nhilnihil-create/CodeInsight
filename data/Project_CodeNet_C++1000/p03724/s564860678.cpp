#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;

  map<int, int> count;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    count[a]++;
    count[b]++;
  }
  for (auto& num : count) {
    if (num.second % 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}