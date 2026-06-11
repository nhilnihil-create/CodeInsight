#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7, K = 61;
long long v[N], d[N], p[N][K], ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i=0; i<n; i++)
        if (v[i].second%2 != i%2)
            ans++;
    cout<<ans/2<<endl;
}
