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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int A[n];
    map<int, int>mp;
    For(i, n, 0) {
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A, A + n, greater<int>());
    int sa = 0, c = 0;
    For(i, a, 0) {
        sa += A[i];
        if (A[a - 1] == A[i])c++;
    }
    cout << fixed << setprecision(6) << (db)sa / (db)a << endl;
    int C[51][51];
    For(i, 51, 0) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    For(i, 51, 1) {
        For(j, 51, 1) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int way = 0;
    if (c == a) {
        For(i, mp[A[a - 1]] + 1, a) {
            if (i <= b)
                way += C[mp[A[a - 1]]][i];
        }
    } else {
        way = C[mp[A[a - 1]]][c];
    }
    cout << way;
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