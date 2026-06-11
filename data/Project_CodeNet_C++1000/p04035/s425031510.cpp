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
    int n, L;
    cin >> n >> L;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] + a[i + 1] >= L) {
            cout << "Possible" << endl;
            for (int j = 0; j < i; ++j) {
                cout << j + 1 << endl;
            }   
            for (int j = n - 2; j >= i; --j) {
                cout << j + 1 << endl;
            }   
            exit(0);
        }   
    }   
    cout << "Impossible" << endl;
}