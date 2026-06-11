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
const int N = 300000;
int a[N];
vector < pair < int, int > > v;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int len = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] != a[i - 1] && i != 1){
            if ((a[i] - a[i - 1] + len) % 2) v.pb({a[i - 1] - 1 - (len + 1) % 2, n - i});
            len = 1;
        } else if (i == 1) len = 1; else len++;
    }
    int ans = (a[n] + len - 1) % 2;
   // cout << v.size() << endl;
    for (auto i: v){
        //cout << i.F << " " << i.S << endl;
        if (i.F - i.S >= 0) ans ^= 1;
    }
    if (ans == 0) cout << "First"; else cout << "Second";
}
