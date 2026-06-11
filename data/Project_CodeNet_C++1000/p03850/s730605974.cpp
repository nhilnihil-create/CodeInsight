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
//const int mod = 1e9 + 7;
const int N = 310000;
int a[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> a[1];
    int t = 0;
    int m = 1;
    for (int i = 1; i < n; i++){
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (s[0] == '-') x = -x;
        if (x > 0 && a[m] > 0){
            a[m] += x;
        } else{
            m++;
            a[m] = x;
        }
    }
    n = m;
    for (int i = 1; i <= n; i++) t += abs(a[i]);
    int p = 0;
    int ans = -1e15;
    for (int i = 1; i <= n; i++){
        if (a[i] > 0){
            p += a[i];
            t -= abs(a[i]);
            continue;
        }
        if (i == n){
            p += a[i];
            continue;
        }
        if (a[i + 1] < 0){
            ans = max(ans, p + t + 2 * a[i]);
        } else{
            ans = max(ans, p + t + 2 * a[i] - 2 * a[i + 1]);
        }
        p += a[i];
        t -= abs(a[i]);
    }
    ans = max(ans, p);
    cout << ans;
}
