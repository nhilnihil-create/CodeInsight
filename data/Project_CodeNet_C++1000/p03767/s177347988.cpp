#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int64_t> a(3 * N);
  for (int i = 0; i < 3 * N; ++i) cin >> a.at(i); 
  sort(a.begin(), a.end(), greater<int64_t>());
 
  int64_t amount = 0;

  for (int i = 0; i < 2 * N; ++i) {
    if (i % 2 == 1) amount += a.at(i);
  }

  cout << amount << endl;
  
}