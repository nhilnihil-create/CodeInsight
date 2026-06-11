#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  rep(i, N) {
    cin >> p[i];
    p[i]--;
  }
  /*
  要素の差以上の値を足さなければ大小は入れ替わらない
  →要素の差を足す最大値(=19999)より大きくしておく
  */
  vector<int> a(N), b(N);
  rep(i, N) {
    a[i] = 20000*i+1;
    b[i] = 20000*(N-i-1)+1;
  }
  rep(i, N)
    a[p[i]] += i;
  rep(i, N) printf("%d%c", a[i], i<N-1?' ':'\n');
  rep(i, N) printf("%d%c", b[i], i<N-1?' ':'\n');
  return 0;
}