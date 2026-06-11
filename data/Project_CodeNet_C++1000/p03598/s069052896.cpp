
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a = x[i];
        int b = k - x[i];
        res += min(a, b) * 2;
    }

    cout << res << endl;
}