#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int m=3;
  if (a==b || b==c || a==c) {
    m--;
  }
  if (a==b && b==c) {
    m--;
  }
  cout << m << endl;
}