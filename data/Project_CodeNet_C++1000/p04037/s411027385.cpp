#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, a[N];
bool check(int x, int y) { return x <= n && y <= a[x - 1]; }   
int get(int i) {
    int ans = 1;
    while (i + 1 < n && a[i + 1] == a[i]) { ++ans; ++i; }
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);
    int x = 0, y = 0;
    while (check(x + 1, y + 1)) { ++x; ++y; }
    --x; --y;
    bool win = 0;
    win |= (a[x] - y - 1) & 1;
    if (y + 1 == a[x + 1]) win |= get(x + 1) & 1;
    if (win) cout << "First\n";
    else cout << "Second\n";
}   