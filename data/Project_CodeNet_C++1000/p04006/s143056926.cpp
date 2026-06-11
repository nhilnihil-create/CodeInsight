#include<bits/stdc++.h>
using namespace std;

const int N = 2005, INF = 2e9;
int mn[N][N];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];

    auto it = min_element(a.begin(), a.end());
    rotate(a.begin(), it, a.end());

    for (int i=0; i<n; i++) {
        mn[i][i-1] = INF;
        for (int j=i; j<n; j++) mn[i][j] = min(a[j], mn[i][j-1]);
    }

    long long ans = 1e18;
    for (int i=0; i<n; i++) {
        long long cur = 1LL*i*x;
        for (int j=0; j<n; j++) {
            int l = max(0, j-i);
            int r = j;
            cur += mn[l][r];
        }
        ans = min(ans, cur);
    }
    cout<<ans<<endl;
}
