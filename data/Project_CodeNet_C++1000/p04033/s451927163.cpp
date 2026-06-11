#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int a,b;
  cin>>a>>b;
  if (a <= 0 && b >= 0) {
    cout << "Zero";
    return 0;
  }
  if (a > 0) {
    cout << "Positive";
    return 0;
  }
  if ((a + b) % 2 == 0) {
    cout << "Negative";
    return 0;
  }
  cout << "Positive";
}
