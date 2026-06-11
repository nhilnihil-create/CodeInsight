#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

constexpr static int MOD = 1000000000 + 7;
constexpr static int inf = INT_MAX / 2;
constexpr static llong INF = 1LL<<31;
constexpr static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong a, b;
    cin >> a >> b;
    if (abs(a - b) <= 1) cout << "Brown";
    else cout << "Alice";
    cout << endl;
    
    return 0;
}