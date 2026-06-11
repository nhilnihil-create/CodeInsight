#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, T;
  cin >> N >> T;
  vector<long long> t(N);
  for (int i=0; i<N; i++) cin >> t.at(i);
  long long X = 0LL;
  for (int i=1; i<N; i++) {
    if (t.at(i)-t.at(i-1)<T) X += t.at(i)-t.at(i-1);
    else X += T;
  }
  X += T;
  cout << X << endl;
  return 0;
}