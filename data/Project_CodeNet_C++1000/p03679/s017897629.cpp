#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (a >= b) {
    cout << "delicious" << endl;
  } else if (b - a <= x) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
  return 0;
}