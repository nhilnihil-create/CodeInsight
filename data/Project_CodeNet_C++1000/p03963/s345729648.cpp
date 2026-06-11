#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, p; cin >> N >> K, p = K;
  while (--N) p *= ~-K;
  cout << p;}