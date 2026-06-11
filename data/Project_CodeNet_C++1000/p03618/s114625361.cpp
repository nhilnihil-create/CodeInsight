#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



string a;
int data[30];

ll f(ll n) {
  return n * (n - 1) / 2;
}

int main () {
  cin >> a;
  int n = a.size();

  Rep(i, n) {
    int tmp = a[i] - 'a';
    data[tmp]++;
  }

  ll ans = f(n);

  Rep(i, 26) {
    ans -= f(data[i]);
  }

  ans++;
  cout << ans << "\n";

}