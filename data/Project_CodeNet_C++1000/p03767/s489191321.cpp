#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int N = 3 * n;
  vector<long long> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  
  long long sum = 0;
  for (int i = N-2; i >= n; i-=2) {
    sum += a.at(i);
  }
  
  cout << sum << endl;
  
}

