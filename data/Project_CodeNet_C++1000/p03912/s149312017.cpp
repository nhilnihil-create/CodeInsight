#include <bits/stdc++.h>
using namespace std;

int solve() {
    int XMAX = 1e5;
    int N, M, x;
    cin >> N >> M;
    vector<int> cn(XMAX+1), cm(M);
    for ( int i = 0; i < N; i++ ) {
        cin >> x;
        cn[x]++;
        cm[x%M]++;
    }
    vector<int> odd(M);
    for ( int i = 1; i <= XMAX; i++ ) {
        if ( cn[i] & 1 ) odd[i%M]++;
    }
    int ans = 0;
    ans += cm[0] / 2;
    if ( (M & 1) == 0 ) {
        ans += cm[M/2] / 2;
    }
    for ( int i = 1; 2*i < M; i++ ) {
        int c1 = cm[i], c2 = cm[M-i];
        int o1 = odd[i], o2 = odd[M-i];
        if ( c1 < c2 ) {
            swap(c1, c2);
            swap(o1, o2);
        }
        if ( o1 >= c2 ) o1 -= c2;
        else if ( o1 > 0 && ((c2 - o1)%2 == 1) ) o1 = 1;
        else o1 = 0;
        ans += c2;
        c1 -= c2;
        ans += (c1 - o1) / 2;
    }
    
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}