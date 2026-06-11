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

const int MAX = 2100000;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int BASE = 1000000000;

const int MOD = 1000000007;

int n, t;
VI A;

int main()
{
  cin >> n >> t;
  FOR (i,0,n)
  {
    int x;
    cin >> x;
    A.PB(x);
  }

  int mx = 0, md = 0, cnt = 0;
  RFOR (i,n,0)
  {
    if (mx > A[i])
    {
      int d = mx - A[i];
      if (d > md)
      {
        cnt = 1;
        md = d;
      }
      else
      if (md == d) ++ cnt;
    }

    mx = max(mx, A[i]);
  }


  cout << cnt << endl;
  
  return 0;
}
