#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int A, B;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> A >> B;
  cout << (A + B) % 24 << "\n";
}