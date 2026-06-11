#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int n;
int p[MAX];

int f()
{
  int sum = n % 2, br_nep = 0, ima1 = 0;

  REP(i, n) {
    sum = (sum + p[i]) % 2;
    br_nep += p[i] % 2;
    ima1 += p[i] == 1;
  }

  if (ima1 || br_nep > 1) return sum;
  
  int gc = 0;
  REP(i, n) {
    if (p[i] % 2)
      p[i]--;
    gc = __gcd(gc, p[i]);
  }

  REP(i, n) p[i] /= gc;
  
  return !f();
}

int main()
{

  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);
  
  printf("%s\n", f() ? "First" : "Second");

  return 0;
}
