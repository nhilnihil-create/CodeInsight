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

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

int alphas[26];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  rep(i, h) {
    string s;
    cin >> s;
    rep(j,w){
      alphas[s[j]-'a']++;
    }
  }
  

  int canK = 0;
  int can2 = 0;

  if (h % 2 && w % 2) {
    canK = 1;
    can2 = (h+w)/2-1;
  } else if (h%2) {
    can2 = w/2;
  } else if (w%2) {
    can2 = h/2;
  }

  rep(i, 26) {
    if (alphas[i]%2) {
      canK--;
    } else if (alphas[i]%4) {
      can2--;
    }
  }

  cout << (canK >= 0 && can2 >= 0 ? "Yes": "No") << endl;
}
