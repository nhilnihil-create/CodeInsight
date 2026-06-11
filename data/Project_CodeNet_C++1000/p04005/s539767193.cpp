#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if(a%2!=0&&b%2!=0&&c%2!=0) {
    if(a>b) swap(a, b);
    if(a>c) swap(a, c);
    if(b>c) swap(b, c);
    cout << a*b << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}