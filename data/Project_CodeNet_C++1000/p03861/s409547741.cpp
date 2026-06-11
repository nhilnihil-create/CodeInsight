#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  long long m=b/x-a/x;
  if (a==a/x*x) {m++;}
  cout << m << endl;
}