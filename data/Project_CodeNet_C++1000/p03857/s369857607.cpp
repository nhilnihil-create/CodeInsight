#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1000000000
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD
#define MAX_N 200001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
struct PairHash{
    size_t operator()(const P &p) const{return p.first * MAX_N + p.second;}
};

int par[2][MAX_N];
int myrank[2][MAX_N];

void init(int n)
{
  for (int i = 0; i < n; i++) {
    par[0][i] = i;
    par[1][i] = i;
    myrank[0][i] = 0;
    myrank[1][i] = 0;
  }
}

int find(int x, int i)
{
  if (par[i][x] == x) return x;
  return par[i][x] = find(par[i][x], i);
}

void unite(int x, int y, int i)
{
  x = find(x, i);
  y = find(y, i);
  if (x == y) return;
  if (myrank[i][x] < myrank[i][y]) {
    par[i][x] = y;
  } else {
    par[i][y] = x;
    if(myrank[i][x] == myrank[i][y]) myrank[i][x]++;
  }
}

bool same(int x, int y, int i)
{
  return find(x, i) == find(y, i);
}

int main()
{
  int N, K, L;
  cin >> N >> K >> L;
  init(N);
  int p, q;
  for (int i = 0; i < K; i++) {
    cin >> p >> q;
    p--; q--;
    unite(p, q, 0);
  }
  int r, s;
  for (int i = 0; i < L; i++) {
    cin >> r >> s;
    r--; s--;
    unite(r, s, 1);
  }

  P idx[MAX_N];
  for (int i = 0; i < N; i++) {
    idx[i] = P(find(i, 0), find(i, 1));
  }

  unordered_map<P, int, PairHash> num;
  for (int i = 0; i < N; i++) {
    num[idx[i]]++;
  }

  for (int i = 0; i < N; i++) {
    cout << num[idx[i]] << endl;
  }

  return 0;
}
