#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == 1) a = 14;
  if(b == 1) b = 14;
  if(a == b) cout << "Draw" << endl;
  else if(a > b) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}