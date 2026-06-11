#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long res = 1;
  while (res * 2 <= N) res *= 2;
  cout << res << endl;
}