#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans = min(n, k)*x;
    ans += max(n-k, 0)*y;
    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    //multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




