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
vector < pair < int, int > > cw, ccw;
void solve(int ps, int pf){
    vector < pair < int, int > > res;
    pair < int, int > z;
    for (int i = 1; i <= n; i++){
        if (w[i] == 1) res.pb({(x[i] + tt) % l, 1}); else
        if (w[i] == 2) res.pb({(x[i] - tt % l + l) % l, 2});
        if (i == pf) z = res.back();
    }
    sort(res.begin(), res.end());
    int q = 0;
    while(res[q] != z){
        q++;
    }
    for (int i = 0; i < n; i++){
        ans[(ps + i - 1) % n] = res[(q + i) % n].F;
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}
void brute(){
    nl = l + l;
    for (int i = 1; i <= n; i++){
        nx[i - 1] = 2 * x[i];
        nw[i - 1] = w[i];
    }
    nt = 2 * t;
    for (int i = 1; i <= nt; i++){
        for (int j = 0; j < n; j++){
            if (nw[j] == 1) nx[j] = (nx[j] + 1) % nl;
            else nx[j] = (nx[j] - 1 + nl) % nl;
        }
            for (int j = 0; j < n; j++){
                if (nx[(j + 1) % n] == nx[j]){
                    if (nw[(j + 1) % n] == 1) nw[(j + 1) % n] = 2; else nw[(j + 1) % n] = 1;
                    if (nw[j] == 1) nw[j] = 2; else nw[j] = 1;
                }
            }
        }
    for (int i = 0; i < n; i++){
        cout << nx[i] / 2 << endl;
    }
    exit(0);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l >> t;
    tt = t;
    srand(time(NULL));
 //   cout << n << " " << l << " " << t << endl;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> w[i];
       // x[i] = rand() % l;
       // while(x[i] <= x[i - 1]){
       //     x[i] = rand() % l;
       //     if (x[i] == l - 1) break;
       // }
        //w[i] = rand() % 2 + 1;
      //  cout << x[i] << " -- " << w[i] << endl;
        if (w[i] == 1) cw.pb({x[i], i});
        else ccw.pb({x[i], i});
    }
    if (t == 1) brute();
    sort(cw.begin(), cw.end());
    reverse(cw.begin(), cw.end());
    sort(ccw.begin(), ccw.end());
    if (ccw.size() == 0){
        for (int i = 1; i <= n; i++){
            cout << (x[i] + t) % l << endl;
        }
        return 0;
    }
    if (cw.size() == 0){
        for (int i = 1; i <= n; i++){
            cout << (x[i] - t % l + l) % l << endl;
        }
        return 0;
    }
    int p, pp;
    p = pp = 0;
    for (int i = 1; i < n; i++){
        if (w[i] == 1 && w[i + 1] == 2){
            p = i;
            pp = i + 1;
            break;
        }
    }
    if (p == 0){
        p = n;
        pp = 1;
    }
   // cout << p << " " << pp << endl;
    for (int i = 0; i < cw.size(); i++){
        if (cw[i].S == p){
            p = i;
            break;
        }
    }
    for (int i = 0; i < ccw.size(); i++){
        if (ccw[i].S == pp){
            pp = i;
            break;
        }
    }
    vector < pair < int, int > > d1, d2;
    for (int i = 0; i < cw.size(); i++){
        int n = cw.size();
        int p1 = cw[(p + i + n) % n].F;
        int p2 = cw[(p + i + n + 1) % n].F;
        if (p1 > p2) d1.pb({p1 - p2, cw[(p + i + n + 1) % n].S}); else d1.pb({l + p1 - p2, cw[(p + i + n + 1) % n].S});
    }
    for (int i = 0; i < ccw.size(); i++){
        int n = ccw.size();
        int p1 = ccw[(pp + i + n) % n].F;
        int p2 = ccw[(pp + i + n + 1) % n].F;
        if (p1 >= p2) d2.pb({l + p2 - p1, ccw[(pp + i + n + 1) % n].S}); else d2.pb({p2 - p1,ccw[(pp + i + n + 1) % n].S});
    }
    int d0;
    int c1 = cw[p].F;
    int c2 = ccw[pp].F;
    if (c2 > c1) d0 = c2 - c1; else d0 = l - c1 + c2;
    if (2 * t <= d0){
        solve(cw[p].S, cw[p].S);
    }
    t += t;
    t -= d0;
    int lb = 0;
    int rb = 1e10;
    //cout << p << " " << pp << endl;
    int ans = ccw[pp].S;
   // for (auto i: d1) cout << i.F << " ";
   // cout << endl;
   // for (auto i: d2) cout << i.F << " ";
    //cout << endl;
    //cout << "t = " << t << endl;
    while(rb - lb > 1){
        int mid = (rb + lb) / 2;
        int l1 = mid / 2 + mid % 2;
        int l2 = mid / 2;
        int k = l1 / d1.size() * l + l2 / d2.size() * l;
        l1 = l1 % d1.size();
        l2 = l2 % d2.size();
        for (int i = 0; i < l1; i++) k += d1[i].F;
        for (int i = 0; i < l2; i++) k += d2[i].F;
        if (k < t){
          //  cout << k << " -- " << mid << endl;
            if (mid % 2) ans = d1[(l1 - 1 + d1.size()) % d1.size()].S; else ans = d2[(l2 - 1 + d2.size()) % d2.size()].S;
            lb = mid;
        }
        else rb = mid;
    }
   // cout << cw[p].S << " " << ans << endl;
    solve(cw[p].S, ans);
}
