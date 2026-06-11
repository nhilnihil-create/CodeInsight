#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;
typedef deque<bool> db;
typedef deque<deque<bool> > ddb;

int main() {
  int n, m;
  cin >> n >> m;
  vi x(n);
  vvi group(m);
  vi eachnum(100005, 0);
  rep (i, n) {
    cin >> x[i];
    group[x[i] % m].eb(x[i]);
    eachnum[x[i]] += 1;
  }
  rep (i, m) {
    sort(all(group[i]));
  }
  vi pairnum(m, 0);
  rep (i, 100005) {
    if (eachnum[i] >= 2) {
      pairnum[i % m] += eachnum[i] / 2;
    }
  }

  int ans = 0;
  ans += (int)group[0].size() / 2;
  if (m % 2 == 0) {
    ans += (int)group[m/2].size() / 2;
  }
  FOR (i, 1, (m-1)/2 + 1) {
    int j = m - i;
    int is, js;
    is = group[i].size();
    js = group[j].size();
    ans += min(is, js);
    int maxi;
    int diff;
    if (is == js) {
      continue;
    } else if (is > js) {
      maxi = i;
      diff = is - js;
    } else {
      maxi = j;
      diff = js - is;
    }
    ans += min(pairnum[maxi], diff/2);
  }
  printf("%d\n", ans);

  return 0;
}
