#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define ll long long int
#define MOD ((int)(1e9) + 7)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b,c;
  cin >> a >> b >> c;
  if((a%2) == 1 || (b%2) == 1 || (c%2) == 1){
    cout << "0\n"; return 0;
  }
  if(a == b && b == c) {
    cout << "-1\n";
    return 0;
  }
  ll cnt = 0;
  while((a%2 == 0) && (b%2 == 0) && (c%2 == 0)) {
    ll pa = a, pb = b, pc=c;
    a = (pb+pc)/2;
    c = (pa+pb)/2;
    b = (pa+pc)/2;
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
