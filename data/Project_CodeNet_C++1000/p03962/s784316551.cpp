#include <bits/stdc++.h>
#define N 101
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> d(N);
  d[a]++;
  d[b]++;
  d[c]++;
  cout << N-count(d.begin(),d.end(),0);
}