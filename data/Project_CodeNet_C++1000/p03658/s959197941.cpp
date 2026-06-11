#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  int t = 0;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < K; i++) {
    t += a[i];
  }
  cout << t << endl;
}