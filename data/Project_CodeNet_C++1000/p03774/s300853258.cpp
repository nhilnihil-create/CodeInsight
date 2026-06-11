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
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    pair<int, int> c[m];
    for(int i = 0; i < m; i++)cin >> c[i].fi >> c[i].se;
    for(int i = 0; i < n; i++){
        int min = INT_MAX, in = -1;
        for(int j = 0; j < m; j++){
            int now = abs(a[i].fi - c[j].fi) + abs(a[i].se - c[j].se);
            if(now < min){
                min = now;
                in = j;
            }
        }
        cout << in + 1 << '\n';
    }
    return 0;
}
// Write Here
