#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int N, a;
    cin >> N;
    map<int,int> A;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        A[a]++;
    }
    if ( A.size() == 1 ) {
        int k = A.begin()->first;
        if ( k == N-1 ) return true;
        if ( 2 * k <= N ) return true;
        return false;
    } else if ( A.size() == 2 ) {
        int k1 = A.begin()->first;
        int k2 = next(A.begin())->first;
        int n1 = A.begin()->second;
        if ( k1 + 1 != k2 ) return false;
        if ( n1 + 1 > k2 ) return false;
        if ( (k2 - n1) * 2 > N - n1 ) return false;
        return true;
    }
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}