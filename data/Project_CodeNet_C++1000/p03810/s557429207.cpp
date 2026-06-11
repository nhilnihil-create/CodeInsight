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
const int N = 500005;
const int K = 20;
int ans[N], x[N], w[N], n, tt, l, t, nl, nx[N], nw[N], nt;
void solve(vector < int > a, int h = 0){
    int s = 0;
    int n = a.size();
    for (auto i: a) s += (i - 1);
    if (s % 2 == 1){
        if (h % 2 == 0){
            cout << "First";
        } else{
            cout << "Second";
        }
        exit(0);
    }
    int cnt = 0;
    int k = 0;
    for (auto i: a) if (i == 1) k++;
    for (auto i: a) if (i % 2) cnt++;
    if (cnt >= 2 || k > 0){
        if (h % 2 == 0){
            cout << "Second";
        } else{
            cout << "First";
        }
        exit(0);
    }
    for (int i = 0; i < n; i++){
        if (a[i] % 2) a[i] -= 1;
    }
    int g = a[0];
    for (int i = 1; i < n; i++) g = __gcd(g, a[i]);
    for (int i = 0; i < n; i++) a[i] /= g;
    solve(a, h + 1);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > a;
    int s = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s += x - 1;
        a.pb(x);
    }
    if (n == 1){
        if (s % 2){
            cout << "First";
        } else{
            cout << "Second";
        }
        return 0;
    }
    solve(a);
}
