#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
vector<pair<int,int>> to[100005];
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i, m)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a]++;
        v[b]++;
    }
    int sum = 0;
    rep(i, n)
    {
        (sum += v[i]) %= 2;
        if (sum % 2 != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}