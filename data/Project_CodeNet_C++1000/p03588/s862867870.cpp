#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, A, B, m(1e9), M{}; cin >> N;
  while (cin >> A >> B) if (A >= M) M = A, m = B;
  cout << M + m;}