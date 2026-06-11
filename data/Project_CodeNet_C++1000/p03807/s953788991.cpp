#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A, cnt = 0;
  while (cin >> A) if (A % 2) cnt++; 
  cout << (!(cnt % 2) ? "YES" : "NO") << "\n";
}