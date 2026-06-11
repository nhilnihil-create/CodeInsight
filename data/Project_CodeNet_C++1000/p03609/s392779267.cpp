#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, t;
  cin >> N >> t;
  if(N >= t) {
    cout << N - t;
  }else {
    cout << 0;
  }
  return 0;
}

