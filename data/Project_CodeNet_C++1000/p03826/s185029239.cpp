#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << max(a*b,c*d) << endl;
  return 0;
}