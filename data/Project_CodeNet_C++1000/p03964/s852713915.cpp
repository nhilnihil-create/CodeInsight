#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll MOD = 1000000007;
ll INF = 1LL << 60;

ll N;
ll a[1111], b[1111];

int main() {
   cin >> N;
   for (int i = 0; i < N; i++) cin >> a[i] >> b[i];

   ll n = 1;
   ll x = 1, y = 1;
   for (int i = 0; i < N; i++) {
      if (i == 0) {
         n = 1;
      } else {
         n = max((a[i-1]*n + a[i]-1) / a[i], (b[i-1]*n + b[i]-1) / b[i]);
      }
      x = a[i] * n;
      y = b[i] * n;
   }
   cout << x + y << endl;

   return 0;
}