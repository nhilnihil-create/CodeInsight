#include<bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool A = a == 5 || a == 7;
  bool B = b == 5 || b == 7;
  bool C = c == 5 || c == 7;
  if(A && B && C && a + b + c == 17) cout << "YES" << endl;
  else cout << "NO" << endl;
}
