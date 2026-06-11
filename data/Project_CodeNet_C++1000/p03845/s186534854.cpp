#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int n; cin >> n;
    vector<int> vec(n);
    int sum = 0;
    rep(i,n) {
        cin >> vec[i];
        sum += vec[i];
    }
    int m; cin >> m;
    vector<int> p(m);
    vector<int> x(m);
    rep(i,m) cin >> p[i] >> x[i];

    rep(i,m) {
        int res = sum;
        res += x[i] - vec[p[i]-1];
        cout << res << "\n";
    }
    return 0;
}

