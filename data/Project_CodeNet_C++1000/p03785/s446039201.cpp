#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;

  int T[N] = {0};
  for (int i = 0; i < N; i++) cin >> T[i];

  sort(T, T+N);

  queue<int> q;
  for (int i = 0; i < N; i++) q.push(T[i]);

  int buses = 0;
  while (0 < q.size()) {
    int first = q.front();
    q.pop();
    for (int i = 1; i < C && 0 < q.size(); i++) {
      int next = q.front();
      if (next <= first + K) q.pop();
      else break;
    }
    buses++;
  }

  cout << buses << endl;
  return 0;
}
