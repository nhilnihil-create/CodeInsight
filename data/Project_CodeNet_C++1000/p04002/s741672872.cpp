#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 3007;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int BASE = 1000000000;

int n, m, k;
map<PII, int> M;
Int R[10];

bool OK(int x, int y)
{
  return x >= 0 && y >= 0 && x+2 < n && y+2 < m;
}

int main()
{
  cin >> n >> m >> k;

  set<PII> Q;
  FOR (i,0,k)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    -- x;
    -- y;
    M[MP(x, y)] = 1;
    FOR (dx,-2,1)
      FOR (dy,-2,1)
      {
        PII p = MP(x+dx, y+dy);
        Q.insert(p);
      }
  }

  R[0] = (n-2) * 1LL * (m-2);

  for(set<PII>::iterator it = Q.begin(); it != Q.end(); ++it)
  {
    int x = it->first;
    int y = it->second;
    if (OK(x, y))
    {
      int c = 0;
      FOR (dx,0,3)
        FOR (dy,0,3)
          c += M[MP(x+dx, y+dy)];
      R[0] --;
      R[c] ++;
    }
  }

  FOR (i,0,10)
    cout << R[i] << endl;


  
  return 0;
}
