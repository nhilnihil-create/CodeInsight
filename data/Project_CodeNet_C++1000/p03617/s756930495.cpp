#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  long long a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
    b = min(a*2,b);
    c = min(b*2,c);
    d = min(c*2,d);
  //  cout << a << b << c << d << endl;
    cout << (n/2)*d+(n%2)*c << endl;
}
