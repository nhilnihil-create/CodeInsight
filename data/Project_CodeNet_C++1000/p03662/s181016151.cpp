#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

vector<int> G[SIZE];
int color[SIZE];

int main(){
  int N;

  scanf("%d", &N);

  for (int i=0; i<N-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> que[2], next;
  int counter[2] = {};

  for (int i=0; i<N; i++)
    color[i] = -1;

  que[0].push(0);
  que[1].push(N-1);

  while(que[0].size() || que[1].size()) {
    for (int i=0; i<2; i++) {
      while(que[i].size()) {
        int p = que[i].front();
        que[i].pop();

        if (color[p] >= 0) continue;
        color[p] = i;
        counter[i]++;

        for (int to : G[p]) {
          next.push(to);
        }
      }
      swap(next, que[i]);
    }
  }

  if (counter[0] <= counter[1]) {
    puts("Snuke");
  } else {
    puts("Fennec");
  }

  return 0;
}
