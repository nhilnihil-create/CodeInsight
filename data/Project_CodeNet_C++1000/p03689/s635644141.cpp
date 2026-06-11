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
const int N = 501, C = 1000 * 1000 * 1000;
int a[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, n1, m1;
    cin >> n >> m >> n1 >> m1;
    if (n % n1 == 0 && m % m1 == 0) {
        cout << "No\n";
        exit(0);
    }   
    int f = C / (n1 * m1);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = f;
    for (int i = n1 - 1; i < n; i += n1) for (int j = m1 - 1; j < m; j += m1) a[i][j] = -((n1 * m1 - 1) * f + 1);
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << a[i][j] << ' '; cout << '\n';
    }   
}   