#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  int A, B;
  int sum = 0;
  rep(i, N) {
    cin >> A >> B;
    sum += B - A + 1;
  }
  cout << sum << endl;
}
