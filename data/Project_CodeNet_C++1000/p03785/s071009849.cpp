#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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
    int n, c, k;
    cin >> n >> c >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    int ptr = 0, ans = 0;
    while (ptr < n) {
        int l = ptr;
        int r = l;
        while (r + 1 < n && r - l + 1 < c && a[r + 1] <= a[l] + k)
            ++r;
        ptr = r + 1;
        ++ans;                
    }   
    cout << ans << endl;
}