#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int res = k * x;
    if(n < k){
        cout << n * x << "\n";
    }
    else{
        res = res + (n - k) * y;
        cout << res << "\n";
    }
    return 0;
 }

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

