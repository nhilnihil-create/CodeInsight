#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
int n;
vector<int> g[N];
int dp[N];

void dfs(int v)
{
    vector<int> a;
    dp[v] = (int)g[v].size();
    for (int u : g[v])
    {
        dfs(u);
        a.push_back(dp[u]);
    }
    sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
    for (int i = a.size()-1; i >=0; i--)
        dp[v] = max(dp[v], a[i] + 1+ i);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        v--;
        g[v].push_back(i);
    }
    dfs(0);
    printf("%d\n", dp[0]);

    return 0;
}
