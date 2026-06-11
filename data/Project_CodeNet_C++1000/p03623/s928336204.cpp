#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;
  cin >> x >> a >> b;
  int A, B;
  if (x>a) A=x-a;
  else A=a-x;
  if (x>b) B=x-b;
  else B=b-x;
  if (A>B) cout << 'B' << endl;
  else cout << 'A' << endl;
}