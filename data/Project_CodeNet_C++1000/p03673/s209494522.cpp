#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;

int main() {
  int n; cin >> n;
  deque<int> v;
  rep(i, n) {
    int a; cin >> a;
    if (i % 2 == (n % 2)) {
      v.push_back(a);
    } else {
      v.push_front(a);
    }
  } 
  for(int a : v) {
    cout << a << ' ';
  }
}
