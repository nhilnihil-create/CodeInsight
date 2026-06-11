#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

void get() {}

template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

int main() {
  int N, M;
  get(N, M);
  vector<vector<int>> G(N);
  FOR(i, M) {
    int A, B;
    get(A, B);
    A--;
    B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  deque<int> ans;
  stack<int> st;
  st.push(0);
  vector<int> visited(N);
  visited[0] = 1;
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    ans.push_back(v);
    visited[v] = 1;
    debug(v);
    bool f = 0;
    for (int x : G[v]) {
      debug("next", x);
      if (!visited[x]) {
        f = 1;
        st.push(x);
      }
    }
    if (!f)
      break;
  }
  st.push(0);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    if (v > 0)
      ans.push_front(v);
    visited[v] = 1;
    debug(v);
    bool f = 0;
    for (int x : G[v]) {
      if (!visited[x]) {
        f = 1;
        st.push(x);
      }
    }
    if (!f)
      break;
  }
  print(ans.size());
  while (!ans.empty()) {
    cout << ans.front() + 1 << " ";
    ans.pop_front();
  }
  cout << endl;
  return 0;
}