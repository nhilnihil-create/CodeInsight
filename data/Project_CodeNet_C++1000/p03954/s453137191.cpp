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
const int mod = 998244353;
const int N = 1000005;
const int K = 25;
int c[N], a[N], b[N], n;
bool ok(int x){
    for (int i = 1; i < n + n; i++) if (a[i] >= x) b[i] = 1; else b[i] = 0;
    int c = b[n];
    int l = n - 1;
    int r = n + 1;
    while(l > 0){
        if (b[l] == c || b[r] == c){
            return (c == 1);
        }
        l--;
        r++;
        c ^= 1;
    }
    return (c == 1);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n + n - 1; i++) cin >> a[i];
    int l = 2;
    int r = n + n - 1;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (ok(mid)) l = mid; else r = mid;
    }
    cout << l;
}
