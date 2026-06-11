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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int ap = 0, ov = 0;
  for(int i=0; i<n; i++) {
    char c = s[i];
    if(c == 'b') ov++;
    if(ap == (a + b) || c == 'c') {
      cout << "No\n";
      continue;
    }
    if(c == 'b' && ov > b) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    ap++;
  }
  return 0;
}
