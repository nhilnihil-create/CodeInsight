#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans = a*b > c*d || a*b == c*d ? a*b : c*d;
  cout << ans << endl;
}