#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int x, t;
  cin >> x >> t;
  cout << max(x - t, 0) << endl;
  return 0;
}