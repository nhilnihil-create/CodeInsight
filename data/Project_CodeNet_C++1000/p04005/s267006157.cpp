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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int a, b, c;
    cin >> a >> b >> c;

    int ans = abs(a * b * (c/2) - a * b * ((c + 1)/2));
    ans = min(ans, abs(b * c * (a/2) - b * c * ((a + 1)/2)));
    ans = min(ans, abs(a * c * (b/2) - a * c * ((b + 1)/2)));
    cout << ans << endl;

}