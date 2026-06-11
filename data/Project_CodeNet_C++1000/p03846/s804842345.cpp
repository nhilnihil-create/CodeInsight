#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  const int MOD = 1000000007;
  int N;
  cin >> N;

  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  vector<int> c(N);
  rep(i, N) {
    c[a[i]]++;
  }

  if (N == 1) {cout << 1 << endl; return 0;}

  if (N % 2 == 0 && c[0] != 0) {cout << 0 << endl; return 0;}
  else if (N % 2 != 0 && c[0] >= 2) {cout << 0 << endl; return 0;}

  long long sum = 1;
  for(int i=1; i<=N/2; i++) {
    if (c[i] > 2) {cout << 0 << endl; return 0;}
    sum *= 2;
    sum %= MOD;
  }

  cout << sum << endl;

  return 0;
}
