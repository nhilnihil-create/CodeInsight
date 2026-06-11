#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    vector<int> odd;
    for ( int i = 0; i < M; i++ ) {
        cin >> A[i];
        if ( A[i] & 1 ) odd.push_back(i);
    }
    if ( odd.size() > 2 ) return -1;
    int o1 = -1, o2 = -1;
    if ( odd.size() > 0 ) o1 = odd[0];
    if ( odd.size() > 1 ) o2 = odd[1];
    vector<ll> na, nb;
    if ( o1 != -1 ) {
        na.push_back(A[o1]);
    }
    for ( int i = 0; i < M; i++ ) {
        if ( i == o1 || i == o2 ) continue;
        na.push_back(A[i]);
    }
    if ( o2 != -1 ) {
        na.push_back(A[o2]);
    }
    if ( na[0] != 1 ) {
        nb.push_back(na[0]-1);
    }
    for ( int i = 1; i < na.size()-1; i++ ) {
        nb.push_back(na[i]);
    }
    if ( o2 != -1 ) {
        nb.push_back(na[na.size()-1] + 1);
    } else {
        if ( na.size() > 1 ) {
            nb.push_back(na[na.size()-1]);
        }
        nb.push_back(1);
    }

    for ( int i = 0; i < na.size(); i++ ) {
        cout << (i != 0 ? " " : "") << na[i];
    }
    cout << "\n";
    cout << nb.size() << "\n";
    for ( int i = 0; i < nb.size(); i++ ) {
        cout << (i != 0 ? " " : "") << nb[i];
    }
    cout << "\n";
    return 0;
}

int main() {
    auto ans = solve();
    if ( ans < 0 ) {
        cout << "Impossible" << "\n";
    }
    return 0;
}