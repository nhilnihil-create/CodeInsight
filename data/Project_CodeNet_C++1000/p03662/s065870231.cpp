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
  int N;
  get(N);
  vector<vector<int>> G(N);
  FOR(i, N - 1) {
    int a, b;
    get(a, b);
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  vector<int> visited(N);
  queue<Pi> q;
  q.push(Pi(1, 0));
  q.push(Pi(2, N - 1));
  visited[0]=1;
  visited[N-1]=2;
  int a = 0, b = 0;
  while (!q.empty()) {
    Pi p = q.front();
    q.pop();
    int c = p.first, v = p.second;
    for (int x : G[v]) {
      if (visited[x] == 0) {
        q.push(Pi(c, x));
        visited[x] = c;
        if (c == 1) {
          a++;
        } else {
          b++;
        }
      }
    }
  }
  if (a > b) {
    print("Fennec");
  } else {
    print("Snuke");
  }
  return 0;
}