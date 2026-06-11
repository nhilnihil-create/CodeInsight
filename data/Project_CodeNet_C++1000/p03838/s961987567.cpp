#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>
#include <stack>

using namespace std;
const long long P = 1000000007;
const long long INF = 1LL << 60;

int main() {
  long long x,y;
  cin >> x >> y;
  int a[2];
  int b[2];
  a[0] = x;
  a[1] = -1*x;
  b[0] = y;
  b[1] = -1*y;
  long long mn = INF;
  long long ans = 0;
  for(int i = 0; i <= 1; i++) {
    for(int j = 0; j <= 1; j++) {
      long long dist = b[j]-a[i];
      if(mn > dist && dist >= 0) {
        ans = i+j+dist;
        mn = dist;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
