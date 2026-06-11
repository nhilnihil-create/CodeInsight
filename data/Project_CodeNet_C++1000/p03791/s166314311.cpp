#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)

using namespace std;

const long long MOD = 1000000000 + 7;
const int MAXN = 100111;
long long a[MAXN];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  long long cnt = 0;
  long long j = 1;
  long long res = 1;
  FOR(i, 1, n) {
    res = (res * (i-cnt)) % MOD;
    if (a[i] >= j) j += 2;
     else cnt++;
  }
  cout << res << endl;
  return 0;
}