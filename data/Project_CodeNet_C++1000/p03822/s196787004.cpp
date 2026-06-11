#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

vector<vector<int>> defeated;
vector<int> height;
void dfs(int node)
{
    height[node] = 0;

    int n = defeated[node].size();
    vector<int> tmp;
    rep(i, n)
    {
        int child = defeated[node][i];
        dfs(child);
        tmp.push_back(height[child]);
    }
    sort(tmp.begin(), tmp.end());

    rep(i, n)
    {
        height[node] = max((int64_t)height[node], tmp[i] + n - i);
    }
}

int main()
{
    int n;
    cin >> n;

    defeated.resize(n);
    height.resize(n);
    rep(i, n - 1)
    {
        int a;
        cin >> a;
        defeated[a - 1].push_back(i + 1);
    }

    dfs(0);
    cout << height[0] << endl;

    return 0;
}