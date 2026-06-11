#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for(int i = 1; i <= n; i++)cout << cnt[i] << '\n';
    return 0;
}
// Write Here
