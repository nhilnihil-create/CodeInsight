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

const int MAX = 7 * 100 * 1000 + 47;
const double EPS = 1e-8;
const int MOD = 1000 * 1000 * 1000 + 7;

int X[MAX], D[MAX];


int main()
{
    int n, l, t;
    scanf("%d%d%d", &n, &l, &t);
    FOR(i, 0, n)
    {
        scanf("%d%d", X + i, D + i);
    }
    int pos = 0;
    FOR(i, 0, n)
    {
        if (D[i] == 1)X[i] = (X[i] + t);
        else X[i] = (X[i] - t);

        if (X[i] > 0)pos += X[i] / l;
        else if (X[i] < 0)pos += (X[i]+1)/l-1;

        X[i] = (X[i] % l + l) % l;
    }
    pos = (pos % n + n) % n;
    sort(X, X + n);
    FOR(i, 0, n)
        printf("%d\n", X[(pos+i)%n]);
}