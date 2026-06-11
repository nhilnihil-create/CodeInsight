#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  if( b - a == c - b ) cout << "YES" << endl;
  else cout << "NO" << endl;
}