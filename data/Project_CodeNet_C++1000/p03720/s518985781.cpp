#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> count(N);
  for (int i= 0; i < M* 2; i++) {
    int x;
    cin >> x;
    count.at(x- 1)++;
  }
  for (int i= 0; i < N; i++) {
    cout << count.at(i) << endl;
  }
}