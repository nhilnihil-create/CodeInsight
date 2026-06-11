#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;

const int MAX_V = 105;
int d[MAX_V][MAX_V];

struct Road {
  int from;
  int to;
  int cost;
};
vector<Road> roads;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  map<int, int> tokubetu;
  map<int, bool> isTokubetu;

  
  if (n <= 2 && x == n) {
    cout << "Yes" << endl;
    rep(i, n*2-1) {
      cout << i+1 << " ";
    }
    cout << endl;
  } else if (x > 1 && x < 2*n-1) {
    cout << "Yes" << endl;
    int idx = 1;
    if (x < n) {
      tokubetu[n-3] = x+2; 
      tokubetu[n-2] = x; 
      tokubetu[n-1] = x-1; 
      tokubetu[n] = x+1;

      isTokubetu[x+2] = true;
      isTokubetu[x+1] = true;
      isTokubetu[x] = true;
      isTokubetu[x-1] = true;
    } else {
      tokubetu[n-3] = x-2; 
      tokubetu[n-2] = x; 
      tokubetu[n-1] = x+1; 
      tokubetu[n] = x-1;

      isTokubetu[x-2] = true;
      isTokubetu[x-1] = true;
      isTokubetu[x] = true;
      isTokubetu[x+1] = true;
    }
    rep(i, 2*n-1) {
      if (tokubetu[i]) {
        cout << tokubetu[i] << " ";
      } else {
        while(isTokubetu[idx]) idx++;
        cout << idx << " ";
        idx++;
      }
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}
