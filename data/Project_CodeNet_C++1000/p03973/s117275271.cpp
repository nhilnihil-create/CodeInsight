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
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    int l = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= l + 1) {

        }
        else {
            ans += (a[i] - 1) / (l + 1);
            a[i] = 1;                           
        }   
        l = max(l, a[i]);
    }
    cout << ans << endl;
}
