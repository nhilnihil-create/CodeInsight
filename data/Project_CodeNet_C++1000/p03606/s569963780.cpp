#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    int a, b; cin >> a >> b; res += b-a+1;
  }
  cout << res << endl;
}