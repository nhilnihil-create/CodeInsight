#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a * b, c * d) << endl;
  return 0;
}