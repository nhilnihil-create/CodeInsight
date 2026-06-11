#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n,0); for (int i=0; i<n; ++i) cin >> v[i];
    int sum = 0;
    for (int i=0; i<n; ++i)
    {
        sum += v[i];
    }
    int ave = sum/n;
    int ave1 = ave + 1;
    int ave2 = ave - 1;
    int ans = 0;
    int ans1 = 0;
    int ans2 = 0;
    for (int i=0; i<n; ++i)
    {
        ans += (ave-v[i]) * (ave-v[i]);
        ans1 += (ave1-v[i]) * (ave1-v[i]);
        ans2 += (ave2-v[i]) * (ave2-v[i]);
    }
    cout << min(ans2, min(ans, ans1)) << endl;
    return 0;
}
