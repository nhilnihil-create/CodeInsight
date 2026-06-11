#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int A, cnt = 0;
  while (cin >> A) if (A % 2) cnt++; 
  cout << (!(cnt % 2) ? "YES" : "NO") << "\n";
}