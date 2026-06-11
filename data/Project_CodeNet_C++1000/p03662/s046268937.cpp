#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <random>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);
typedef pair<int, int> P;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
#define OUTPUT(i) (cout << (ll)i << endl)
#define ALL(a) ((a).begin(), (a).end())

bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}
int n;
int fennec, snuke;

int dF[100010], dS[100010];
vector<vector<int>> G(100010);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(15);
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < 100010; ++i)
    {
        dF[i] = -1;
        dS[i] = -1;
    }
    queue<int> q;
    q.push(0);

    dF[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < (int)G[v].size(); ++i)
        {
            if (dF[G[v][i]] == -1)
            {
                dF[G[v][i]] = dF[v] + 1;
                q.push(G[v][i]);
            }
        }
    }

    q.push(n - 1);
    dS[n - 1] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)G[v].size(); ++i)
        {
            if (dS[G[v][i]] == -1)
            {
                dS[G[v][i]] = dS[v] + 1;
                q.push(G[v][i]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (dS[i] < dF[i])
            snuke++;
        else
            fennec++;
    }
    if (snuke >= fennec)
        cout << "Snuke" << endl;
    else
        cout << "Fennec" << endl;
    return 0;
}