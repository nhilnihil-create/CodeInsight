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

    const int T = 1000 * 1000 * 1000;
    
    int n;
    cin >> n;
    vector <int> p(n + 1), val(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        val[p[i]] = T - n + i;
    }   
    vector <int> a(n + 1), b(n + 1);
    const int INF = 1e9 + 7;
    int cur = INF, ra = 0;
    for (int i = 1; i <= n; ++i) {
        cur = min(cur - 1, val[i] - ra - 1);
        b[i] = cur;                         
        a[i] = val[i] - b[i];

        if (b[i] < 0 || a[i] < 0)
            exit(1);

        ra = a[i];
    }   
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << endl;
}