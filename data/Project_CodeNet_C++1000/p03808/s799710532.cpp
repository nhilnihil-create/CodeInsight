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
    int n;
    cin >> n;
    vector <int> a(n), start(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];    
    }   
    if (sum % ((n + 1) * n / 2)) {
        cout << "NO" << endl;
        exit(0);
    }   
    int k = sum / ((n + 1) * n / 2);
    for (int i = 0; i < n; ++i) {
        int r = (i + 1) % n;
        if (a[r] > a[i] + k) {
            cout << "NO" << endl;
            exit(0);
        }   
        if ((a[i] + k - a[r]) % n) {
            cout << "NO" << endl;
            exit(0);
        }   
        start[r] = (a[i] + k - a[r]) / n;
    }   

    int tot = 0;
    for (int e : start)
        tot += e;

    if (tot == k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}