#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 100100;

int n, m, a, b;

set <int> s[MAXN];
vector <int> v[MAXN];
deque <int> sol;

int main() {
	scanf("%d %d",&n,&m);
	REP(i, m) {
		scanf("%d %d",&a,&b);
		s[a].insert(b);
		s[b].insert(a);
    v[a].push_back(b);
    v[b].push_back(a);
	}

  sol.push_back(1);
  sol.push_back(v[1][0]);

  REP(i, (int)v[1].size()) s[v[1][i]].erase(1);
  REP(i, (int)v[sol.back()].size()) s[v[sol.back()][i]].erase(sol.back());

  while (!s[sol.front()].empty()) {
    int A = *s[sol.front()].begin();
    sol.push_front(A);
    REP(i, (int)v[A].size()) s[v[A][i]].erase(A);
  }
  while (!s[sol.back()].empty()) {
    int A = *s[sol.back()].begin();
    sol.push_back(A);
    REP(i, (int)v[A].size()) s[v[A][i]].erase(A);
  }

  printf("%d\n",(int)sol.size());
  REP(i, (int)sol.size()) printf("%d ",sol[i]);
  puts("");

	return 0;
}
