#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string X;
  cin >> X;
  int N = X.size();
  for (int i = 1; i < X.size(); i++) {
    if (X[i-1] == 'S' && X[i] == 'T') {
      X.erase(i-1,2);
      i-=2;
    }
  }
  cout << X.size() << endl;
  return 0;
}