#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  int64_t temp = 1;
  FOR(i,0,N) temp = (temp * (i+1)) % 1000000007;
  cout << temp << endl;
  return 0;
}