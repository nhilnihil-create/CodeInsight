// LNU_Algotesters
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
#include <fstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
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
const int MAX = 100 * 1000 + 47;

int X[MAX];

VI mult(VI &A, VI &B)
{
    VI res(SZ(A));
    FOR(i, 0, SZ(A))
        res[i] = B[A[i]];
    return res;
};


VI BP(VI& P, LL n)
{
    VI res;
    FOR(i, 0, SZ(P))res.PB(i);
    while(n)
    {
        if (n & 1)res = mult(res, P);
        P = mult(P, P);
        n >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    FOR(i, 0, n)scanf("%d", X + i);
    int m;
    LL k;
    scanf("%d%lld", &m, &k);
    VI P;
    FOR(i, 0, n-1)
        P.PB(i);
    FOR(i, 0, m)
    {
        int x;
        scanf("%d", &x);
        --x;
        swap(P[x], P[x-1]);
    }
    //cout << m << endl << endl;
    P = BP(P, k);
    LL cur = X[0];
    FOR(i, 0, n)
    {
        printf("%lld\n", cur);
        if (i < SZ(P))cur += X[P[i] + 1] - X[P[i]];
    }
}

