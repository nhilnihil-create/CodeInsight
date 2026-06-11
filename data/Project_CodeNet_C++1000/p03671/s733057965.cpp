#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << a + b + c - max(a, max(b,c)) << "\n";
}
