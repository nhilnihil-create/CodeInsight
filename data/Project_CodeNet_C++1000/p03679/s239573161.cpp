#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(b >= c) cout << "delicious";
  else if(a + b < c) cout << "dangerous";
  else cout << "safe";
}