#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    int sum = 0;
    for (auto x : mp)
    {
        if (x.second >= 2)
            sum += x.second - 1;
    }
    if (sum % 2 == 0)
        OP(mp.size());
    else
        OP(mp.size() - 1);
    return 0;
}