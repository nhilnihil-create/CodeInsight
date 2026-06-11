#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> t = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> t.at(i);
  }
  sort(t.begin(), t.end());

  int busCount = 0;
  int i = 0;
  while (i < N) {
    int firstT = t.at(i);
    int passengerCount = 0;
    while (i < N && passengerCount < C && t.at(i) <= firstT + K) {
      i++;
      passengerCount++;
    }
    busCount++;
  }
  cout << busCount << endl;
  return 0;
}