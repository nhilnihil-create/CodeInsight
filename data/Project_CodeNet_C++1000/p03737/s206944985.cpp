#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A, B, C;
  cin >> A >> B >> C;
  char X, Y, Z;
  int o = 'A' - 'a';
  X = A.at(0) + o;
  Y = B.at(0) + o;
  Z = C.at(0) + o;
  cout << X << Y << Z << endl;
}