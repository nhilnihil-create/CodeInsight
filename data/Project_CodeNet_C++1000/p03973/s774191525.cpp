#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
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
    int n;
    cin >> n;
    i64 ans = 0, lo = 0;
    for (int i = 0; i < n; i++)
    {
        i64 a;
        cin >> a;
        i64 k = (a - 1) / (lo + 1);
        ans += k;
        if (a == lo + 1 || i == 0)
            lo++;
        //print(i, k, lo);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
