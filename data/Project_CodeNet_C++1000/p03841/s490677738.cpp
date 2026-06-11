#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int N;
    cin >> N;
    vector<int> X(N+1);
    for ( int i = 1; i <= N; i++ ) {
        cin >> X[i];
    }
    vector<pair<int,int>> xi;
    for ( int i = 1; i <= N; i++ ) {
        xi.emplace_back(X[i], i);
    }
    sort(xi.begin(), xi.end());
    vector<int> ans(N*N+1);
    for ( int i = 1; i <= N; i++ ) {
        ans[X[i]] = i;
    }
    int h = 1;
    for ( int k = 0; k < N; k++ ) {
        int x = xi[k].first;
        int i = xi[k].second;
        for ( int j = 0; j < i-1; j++ ) {
            while( h < x && ans[h] > 0 ) h++;
            if ( h >= x ) return false;
            ans[h] = i;
            h++;
        }
    }
    h = N*N;
    for ( int k = N-1; k >= 0; k-- ) {
        int x = xi[k].first;
        int i = xi[k].second;
        for ( int j = i; j < N; j++ ) {
            while( h > x && ans[h] > 0 ) h--;
            if ( h <= x ) return false;
            ans[h] = i;
            h--;
        }
    }
    cout << "Yes" << "\n";
    for ( int i = 1; i <= N*N; i++ ) {
        cout << (i != 1 ? " " : "") << ans[i];
    }
    cout << "\n";
    return true;
}

int main() {
    auto ans = solve();
    if ( !ans ) cout << "No" << "\n";
    return 0;
}