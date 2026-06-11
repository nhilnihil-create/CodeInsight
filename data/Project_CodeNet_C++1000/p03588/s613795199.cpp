#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> P;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        P.push_back(make_pair(a,b));
    }
    sort(P.begin(),P.end());
    int ans = 0;
    rep(i,n-1) {
        ans += P[i+1].first - P[i].first;
    }
    ans += P[0].first - 1;
    ans += P[n-1].second;
    cout << ans + 1 << "\n";
    return 0;
}