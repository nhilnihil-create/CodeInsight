#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int A[100000];

int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}
bool f() {
  int ones = 0, sum = 0;
  rep(i, N) {
    if (A[i] % 2 == 1) {
      ones++;
    }
    sum += (A[i]%2);
    sum %= 2;
  }
  if (sum != N%2) return true;
  if (ones != 1) return false;

  rep(i, N) {
    if (A[i] % 2 == 1) {
      A[i]--;
      if (A[i] == 0) return false;
    }
  }
  int g = A[0];
  rep(i, N) {
    g = gcd(g, A[i]);
  }
  rep(i, N) A[i] /= g;
  return !f();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];

  if (f()) cout << "First\n";
  else cout << "Second\n";
  return 0;
}
