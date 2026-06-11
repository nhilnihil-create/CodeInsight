#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int x,a,b; cin>>x>>a>>b;
  if (a - b >= 0) {
    cout << "delicious";
  } else if (b - a <= x) {
    cout << "safe";
  } else {
    cout << "dangerous";
  }
}
