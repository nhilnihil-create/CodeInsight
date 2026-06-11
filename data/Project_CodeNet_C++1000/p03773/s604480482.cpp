#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define pb push_back
#define READ(file) freopen(FILE, "r", stdin)
#define WRITE(file) freopen(FILE, "w", stdout)
#define loop(i, s, e) for (ll i = s; i < e; i++)

using namespace std;

// #define cases

void test(size_t t)
{
}

void solve()
{
    int a, b;
    cin >> a >> b;

    cout << (a + b) % 24 << endl;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

#ifdef cases
    size_t T;
    cin >> T;
    for (size_t t = 1; t < T + 1; t++)
        test(t);
#else
    solve();
#endif

    int c;
    cin >> c;
    return 0;
}
