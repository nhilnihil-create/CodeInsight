#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> v;
  int input;
  int ttl = 0;
  rep (i, N) {
    cin >> input;
    if (input < abs(input - K)) {
      ttl += input * 2;
    } else {
      ttl += abs(input - K) * 2;
    }
  }
  cout << ttl << endl;
}
