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
  int k,t;
  cin >> k >> t;
  int a[t];
  for(int i = 0; i < t; i++) {
    cin >> a[i];
  }
  sort(a,a+t,greater<int>());
  cout << max(0,a[0]-1 - (k-a[0])) << endl;
  return 0;
}
