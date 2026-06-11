//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//{akari : 1D, yukari : 2D, maki : 3D} vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//{akane : ascending order, aoi : decending order} priority queue
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Libraries ---------------------------------//

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
    i64 k;
    cin >> k;
    i64 x = min(i64(50), k / i64(1e16) + 1);
    if (x == 1)
    {
        cout << 2 << endl;
        if (k & 1)
        {
            cout << k / 2 << ' ' << k / 2 + 3 << endl;
        }
        else
        {
            cout << k / 2 + 1 << ' ' << k / 2 + 1 << endl;
        }
        return;
    }
    i64 lo = 0, hi = 1e16 + 1;
    while (lo + 1 < hi)
    {
        i64 m = (hi + lo) / 2;
        (m * x <= k ? lo : hi) = m;
    }
    i64 a = lo, off = 0;
    int up = x;
    cout << x << endl;
    akari<i64> ans(x);
    for (int i = 0; i < x; i++)
    {
        ans[i] = a + x - 1 + off;
        if (a * i + (a - 1) * (x - i) == k)
        {
            off = 1;
            up = i;
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (i64 i = 0; i < k - a * x; i++)
    {
        ans[i % up] += x;
        for (int j = 0; j < x; j++)
        {
            if (j == i % up)
            {
                continue;
            }
            ans[j]--;
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}
