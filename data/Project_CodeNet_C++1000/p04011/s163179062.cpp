#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <map>
#include <cassert>
#include <sstream>
#include <numeric>
#include <regex>
#include <cctype>
#include <utility>
#include <stdio.h>
#include <set>
#include <queue>
#include <deque>

typedef long long ll;

#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define MOD 1000000007
#define pb push_back
#define llnums vector<ll>
#define FOR(i,n) for(int i{0}; i < n; ++i)

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k,x,y,ans=0;
  cin >> n >> k >> x >> y;
  if (n > k) {
      for (int i=0; i < k; i++) {
          ans += x;
      }
      for (int i=k; i < n; i++) {
          ans += y;
      }
  }
  else {
      for (int i=0; i < n; i++) {
          ans += x;
      }
  }
  cout << ans << '\n';
  return 0;
}







