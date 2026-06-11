#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int MAX = 100000;

int main() {
  string x;
  cin >> x;
  int n = x.length();

  stack<char> q;
  for (int i = 0; i < n; i++) {
    if (q.size() > 0 && x[i] == 'T' && q.top() == 'S') {
      q.pop();
    } else {
      q.push(x[i]);
    }
  }
  cout << q.size() << endl;
}
