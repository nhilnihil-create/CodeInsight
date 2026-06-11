#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> t = vector<int>(N);
  for (int i = 0; i < N; i++) cin >> t.at(i);
  sort(t.begin(), t.end());

  int busCount = 0;
  for (int i = 0; i < N;) {
    int start = i;
    while (i < N && i - start < C && t.at(i) <= t.at(start) + K) i++;
    busCount++;
  }
  cout << busCount << endl;
  return 0;
}