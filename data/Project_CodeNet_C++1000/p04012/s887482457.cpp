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
#include <stack>

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
  int arr[123];
  FOR(i, 123) {
      arr[i] = 0;
  }
  string w;
  cin >> w;
  for (auto const& a: w) {
      arr[a]++;
  }
  bool ok=true;
  for (int i=97; i < 123; i++) {
      if (arr[i] % 2 != 0) {
          ok =false;
          break;
      }
  }
  if (ok) {cout << "Yes\n";}
  else {cout << "No\n";}
  return 0;
}






