#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const long long MAXN = 1e5 + 21, inf = 1e18 + 21, LG = 20;

int n;
map <int, int> mp;
int a[MAXN];
long long ans;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 0;
    }

    int cnt = 0;
    for (auto &y: mp)
        y.ss = cnt++;

    for (int i = 0; i < n; i++)
        ans += (i % 2 != mp[a[i]] % 2);
    
    cout << ans / 2 << '\n';
    return 0;
}
