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
const int N = 600000;
vector < pair < int, int > > ans;
int cnt;
int t;
vector < int > solve(int n){
    vector < int > res;
    if (n == 1) return res;
    vector < int > v;
    if (n % 2){
        v = solve(n - 1);
        res.pb(v.size() + 1);
        for (auto i: v) res.pb(i);
        return res;
    } else{
        v = solve(n / 2);
        for (auto i: v) res.pb(i);
        res.pb(v.size() + 1);
        return res;
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > v = solve(n + 1);
    cout << v.size() * 2 << endl;
    for (auto i: v) cout << i << " ";
    for (int i = 1; i <= v.size(); i++) cout << i << " ";
}
