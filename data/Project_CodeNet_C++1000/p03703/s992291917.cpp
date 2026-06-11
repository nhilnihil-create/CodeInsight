#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, K;
int a[200100];
vector<int> vals;
map<int, int> idx;
int bit[200100];
 
int acc(int i) {
    int s = 0;
    while (i>0) {
        s += bit[i];
        i -= i&(-i);
    }
    return s;
}
 
void add(int i, int x) {
    i++;
    while (i<=N+10) {
        bit[i] += x;
        i += i&(-i);
    }
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, N) cin >> a[i];
    int s = 0;
    vals.pb(0);
    rep(i, N) {
        s += a[i];
        vals.pb(s-K*(i+1));
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    rep(i, vals.size()) idx[vals[i]] = i;
    
    int ans = 0;
    s = 0;
    add(idx[0], 1);
    rep(i, N) {
        s += a[i];
        ans += acc(idx[s-K*(i+1)]+1);
        //cout << s-K*i << endl;
        //cout << acc(idx[s-K*(i+1)]+1) << endl;
        add(idx[s-K*(i+1)], 1);
    }
    cout << ans << endl;
}