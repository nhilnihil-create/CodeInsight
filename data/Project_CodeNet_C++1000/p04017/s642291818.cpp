//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Dubug Functions ---------------------------//
inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}
//------------------------------- Solver ------------------------------------//

void solve()
{
    int n, q, l;
    cin >> n;
    akari<int> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    cin >> l >> q;
    yukari<int> dp(n, akari<int>(21));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = distance(xs.begin(), upper_bound(xs.begin(), xs.end(), xs[i] + l)) - 1;
    }
    for (int k = 0; k < 20; k++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][k + 1] = dp[dp[i][k]][k];
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        a--, b--;
        int ans = 0;
        for (int k = 20; k >= 0; k--)
        {
            if (dp[a][k] < b)
            {
                a = dp[a][k];
                ans |= 1 << k;
            }
        }
        ans++;
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}
