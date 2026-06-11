#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  for (int i = 0; i < 3 * N; i++) cin >> a.at(i);

  sort(a.begin(), a.end(), greater<int>());
  
  long long sum = 0;
  for (int i = 1; i < 2 * N; i += 2) {
    sum += a.at(i);
  }
  
  cout << sum << endl;
}
