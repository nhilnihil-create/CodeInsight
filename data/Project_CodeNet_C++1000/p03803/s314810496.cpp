#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == b) cout << "Draw" << endl;
  else if(a == 1) cout << "Alice" << endl;
  else if(b == 1) cout << "Bob" << endl;
  else if(a > b) cout << "Alice" << endl;
  else if(a < b) cout << "Bob" << endl;
}