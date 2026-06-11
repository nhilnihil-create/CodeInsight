#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  if (n == 1) {
    if (a == b) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  else if (a > b){
    cout << 0 << endl;
  }
  else {
    cout << b*(n-2)-a*(n-2)+1<< endl;
  }
  return 0;
}