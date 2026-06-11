#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}