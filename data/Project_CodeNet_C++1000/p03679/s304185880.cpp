#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int x,a,b;
  cin >> x >> a >> b;
  a = (-1)*a;
  if(a+b <= 0) cout << "delicious" << endl;
  if(0 < a+b && a+b <= x) cout << "safe" << endl;
  if(x < a+b) cout << "dangerous" << endl;
  return 0;
}
