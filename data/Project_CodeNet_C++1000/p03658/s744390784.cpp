#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> stick(N);
  for (int i=0; i<N; i++) cin >> stick[i];
  sort(stick.begin(), stick.end(), greater<int>());
  int length=0;
  for (int i=0; i<K; i++) length+=stick[i];
  cout << length << endl;
}