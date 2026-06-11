#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> l(N),r(N);
  for (int i = 0; i < N; i++) {
    cin >> l.at(i) >> r.at(i);
  }

  int  ans =  0;
  for (int i = 0; i < N; i++) {
    for (int j = l.at(i); j <= r.at(i); j++) {
      ans++;
    }
  }
  cout << ans << endl;
}
