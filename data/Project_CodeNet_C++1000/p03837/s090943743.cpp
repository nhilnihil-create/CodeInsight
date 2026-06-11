#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);
const int MAXN = 105;
const int INF = 1e9+7;
int dis[MAXN];
vector<P> v[MAXN];
int n, m;
int d[MAXN][MAXN];
int a[MAXN][MAXN];
int main()
{
    //FIN;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int  j =1; j <= n; j++)
        {
            a[i][j] = d[i][j] = INF;
        }
    }
    for(int i = 0; i <= n; i++)
    {
        d[i][i] = a[i][i] = 0;
    }
    for(int i = 0 ; i< m; i++)
    {
        int u , v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = d[u][v] = d[v][u] = w;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n ; j++)
            {
                if(i != j && i != k)
                {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n ;j++)
        {
            if(d[i][j] < INF && a[i][j] != d[i][j]) ans++;
        }
    }
    cout << ans << endl;
}