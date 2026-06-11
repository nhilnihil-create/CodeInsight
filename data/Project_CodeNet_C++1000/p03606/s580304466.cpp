#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;

    return 0;
}