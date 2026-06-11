#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l; cin >> n >> l;
    vector<string> v(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for ( auto x: v ) cout << x;
    cout << endl;
    return 0;
}
