#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bitset<8> s;
  int reinbow_count = 0;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a/400 >= 8) reinbow_count++;
    else s.set(a/400);
  }
  if (s.count() == 0) cout << 1 << " ";
  else cout << s.count() << " ";
  cout << s.count() + reinbow_count << endl;
}