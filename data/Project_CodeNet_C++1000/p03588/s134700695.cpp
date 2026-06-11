#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int n; cin >> n;
    vector<P> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    cout << p[n-1].first + p[n-1].second;
}
