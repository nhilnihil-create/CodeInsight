#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2 * N - 1)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    if (N == 2)
    {
        rep(i, 0, 3)
        {
            cout << i + 1 << endl;
        }
        return;
    }

    vector<int> ans(2 * N - 1, -1);
    vector<bool> used(2 * N, false);
    if (x == 2)
    {
        ans[N - 2] = x + 1;
        ans[N - 1] = x;
        ans[N] = x - 1;
        ans[N + 1] = x + 2;
        used[x + 1] = used[x] = used[x - 1] = used[x + 2] = true;
    }
    else
    {
        ans[N - 2] = x - 1;
        ans[N - 1] = x;
        ans[N] = x + 1;
        ans[N + 1] = x - 2;
        used[x - 1] = used[x] = used[x + 1] = used[x - 2] = true;
    }

    int num = 1;
    rep(i, 0, 2 * N - 1)
    {
        if (ans[i] > 0) continue;
        while (used[num]) ++num;
        ans[i] = num;
        used[num] = true;
    }

    for (const int i : ans)
    {
        cout << i << endl;
    }
}
