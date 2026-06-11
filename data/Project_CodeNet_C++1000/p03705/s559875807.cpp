#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  ull n,a,b;
  cin>>n>>a>>b;
  if (n == 1) {
    if (a == b) {
      cout << 1;
    } else {
      cout << 0;
    }
    return 0;
  }
  if (a > b) {
    cout << 0;
    return 0;
  }
  // b(n-1)+a - a(n-1)+b + 1
  cout << (b * (n-1) + a) - (a * (n-1) + b) + 1;
}
