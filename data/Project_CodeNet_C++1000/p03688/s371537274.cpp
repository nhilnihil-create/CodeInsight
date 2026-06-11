#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define P pair<int, int>
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define LAST(x) (x)[(x).size() - 1]
#define GI(name) \
  int(name);     \
  scanf("%d", &(name))
#define GI2(name1, name2) \
  int(name1), (name2);    \
  scanf("%d %d", &(name1), &(name2))
#define GI3(name1, name2, name3) \
  int(name1), (name2), (name3);  \
  scanf("%d %d %d", &(name1), &(name2), &(name3))
#define GVI(name, size)    \
  vector<int>(name)(size); \
  FOR(i, (size)) scanf("%d", &(name)[i])
#define GS(name) \
  string(name);  \
  cin >> (name);
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  FOR(i, v.size() - 1) { ret += to_string(v[i]) + ","; }
  if (v.size() > 0) {
    ret += to_string(LAST(v));
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

int main() {
  GI(N);
  GVI(a, N);
  map<int, int> list;
  FOR(i, N) { list[a[i]]++; }
  if (list.size() > 2) {
    print("No");
    return 0;
  }
  int A, ca, cb;
  if (list.size() == 2) {
    A = list.begin()->first;
    ca = list.begin()->second;
    if (list.rbegin()->first > A + 1) {
      print("No");
      return 0;
    }
    cb = list.rbegin()->second;
  } else {
    A = list.begin()->first;
    if (A == N - 1 || N % A == 0) {
      print("Yes");
    } else {
      print("No");
    }
    return 0;
  }
  if (ca - 1 + min(1, cb) <= A && A <= ca - 1 + cb / 2) {
    print("Yes");
  } else {
    print("No");
  }
  return 0;
}