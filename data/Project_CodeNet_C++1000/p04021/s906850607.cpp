#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<pair<ll,int>> v(N);
    for(int i=0;i<N;i++) {
        cin >> v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<N;i++) {
        if((v[i].second&1) != (i&1)) cnt++;
    }
    cout << (cnt+1)/2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
