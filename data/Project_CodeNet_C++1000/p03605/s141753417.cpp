#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c;
  cin >> a;
  b = a / 10;
  c = a % 10;
  if(c == 9 || b == 9)cout << "Yes";
  else cout << "No";
}
