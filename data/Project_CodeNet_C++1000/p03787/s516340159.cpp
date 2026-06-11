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

#define F(i, n) for(int i = 0; i < n; ++i)
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

const int MAX =2*100000 + 47;

VI G[MAX];
int C[MAX];
int cnt[MAX];
bool b;

void dfs(int v, int c)
{
    C[v] = c;
    cnt[c]++;
    FOR(i, 0, SZ(G[v]))
    {
        int to = G[v][i];
        if (C[to] != -1)
        {
            if (C[to] == C[v])
                b =  false;
            continue;
        }
        
        dfs(to, c ^ 1);
        
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 0, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        G[x].PB(y);
        G[y].PB(x);
    }
    FILL(C, -1);
    
    LL NB = 0;
    LL C1 = 0, CC = 0;
    
    FOR(i, 0, n)
        if (C[i] == -1)
        {
            cnt[0] = cnt[1] = 0;
            b = 1;
            dfs(i, 0);
            if (!b)++NB;
            else
            {
                if (!cnt[1])++C1;
                else ++CC;
            }
        }
    
    LL res = NB * NB;
    res += 2 * CC * CC;
    res += 2 * CC * NB;
    res += 2 * C1 * n  - C1 * C1;
    cout << res << endl;
    
    
}

