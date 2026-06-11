#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define MX 1e5

const int mod = 1e9 + 7;

void solve() {
    vector<int> v(3,0);
    FOR(3){
        cin >> v[i];
    }
    sort(bn(v));
    cout << v[0]+v[1];
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
