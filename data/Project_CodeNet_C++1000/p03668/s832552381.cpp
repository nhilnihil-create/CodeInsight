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
#include <complex>

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

const int MAX = 2 * 1000 * 100 + 47;
const int MIN = 404;
const int MOD = INF;


VI G[MAX];


int dfs(int v, int p = -1)
{
    int g = 0;
    FOR(i, 0, SZ(G[v]))
    {
        int to = G[v][i];
        if (to == p)continue;
        int gt = dfs(to, v);
        g ^= gt + 1;
    }
    return g;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    FOR(i, 0, n-1)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        G[x].PB(y);
        G[y].PB(x);
    }
    if (!dfs(0))printf("Bob\n");
    else printf("Alice\n");
    
    return 0;
}



