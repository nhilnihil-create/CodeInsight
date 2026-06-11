#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 20005;
const int K = 50;
bitset < 5001 > bs1, bs2, bs3, s[N], p[N], bs;
int a[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int sum = 0;
    int c = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] > k){
            a[i] = 0;
            c++;
        }
        sum += a[i];
    }
    p[0][0] = 1;
    for (int i = 1; i <= n; i++){
        p[i] = p[i - 1] | (p[i - 1] << a[i]);
    }
    s[n + 1][0] = 1;
    for (int i = n; i >= 1; i--){
        s[i] = s[i + 1] | (s[i + 1] << a[i]);
    }
    if (sum < k){
        cout << n - c;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        int r = k - 1;
        int l = k - a[i];
        bs.reset();
        for (int j = l; j <= r; j++) bs[j] = 1;
        bs1 = p[i - 1];
        bs2 = s[i + 1];
        int r1 = 0;
        int r2 = 0;
        for (int j = 0; j < k; j++) if (bs1[j]) r1 = max(r2, j);
        for (int j = 0; j < k; j++) if (bs2[j]) r2 = max(r1, j);
        int f = 0;
        if (a[i] == 0) continue;
        if (r - l + 1 < K){
            for (int j = l; j <= r && f == 0; j++){
                for (int q = 0; q <= j && f == 0; q++){
                    if (bs1[q] && bs2[j - q]) f = 1;
                }
            }
        }
        if (bs1.count() > bs2.count()) swap(bs1, bs2);
        if ((bs1 & bs).count() != 0) f = 1;
        if ((bs2 & bs).count() != 0) f = 1;
        vector < int > v;
        for (int j = 0; j < k; j++){
            if (bs1[j]){
                v.pb(j);
            }
        }
        random_shuffle(v.begin(), v.end());
        for (auto j: v){
            if (((bs2 << j) & bs).count() != 0) f = 1;
            if (f) break;
        }
        if (f == 0){
            ans++;
        }
    }
    cout << ans;
}
