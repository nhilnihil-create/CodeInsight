#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M,a,b;
  cin >> N;
  vector<int> counter(N);
  for (cin >> M; M; counter[a-1]++, counter[b-1]++, M--) {
    cin >> a >> b;
  }
  for (int i = 0; i < N; i++) {
    cout << counter[i] << endl;
  }
}