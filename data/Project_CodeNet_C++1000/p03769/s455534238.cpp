#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 17;
const double EPS = 1e-8;
const int MOD = 1000 * 1000 * 1000 + 7;


VI A;
int cur;

void rec(LL x)
{
    if (x == 1)return ;
    int val = ++cur;
    if (x & 1)
    {
        A.PB(val);
        rec(x-1);
    }
    else
    {
        rec(x/2);
        A.PB(val);
    }
}


int main()
{
    LL n;
    cin >> n;
    rec(n+1);
    int k = SZ(A);
    RFOR(i, k+1, 1)
        A.PB(i);
    cout << SZ(A) << endl;
    FOR(i, 0, SZ(A))cout << A[i] << " ";
}
