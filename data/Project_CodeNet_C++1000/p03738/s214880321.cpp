#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define oset tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >
#define endl '\n'
#define int long long int
#define db long double
#define str string
#define mod 1000000007
#define ff first
#define ss second
#define PQi priority_queue<int>
#define Vi vector<int>
#define Si set<int>
#define Li list<int>
#define mk make_pair
#define pii pair<int,int>
#define all(x) (x.begin(),x.end())
#define pb(x) push_back(x)
#define For(i,n,s) for(int i=s;i<n;i++)
#define mat2D(T,r,c) vector<vector<int> > T(r,vector<int>(c))
#define vec2D vector<vector<int> >
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define getVal(x) {int val;cin>>val;x.pb(val);}
#define debug(x) {for(auto i :x) cout << i << " ";cout << endl;}

bool isSmaller(string a, string b) {
    int n = a.length(), m = b.length();
    if (n < m)
        return true;
    if (n > m)
        return false;
    For(i, n, 0) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }
    return false;
}

void solve() {
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "EQUAL";
    } else {
        cout << (isSmaller(a, b) ? "LESS" : "GREATER");
    }
}

int32_t main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
# endif
    solve();
    return 0;
}