#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    int n; cin >> n;
    int cur = 1;
    int ans = 0;
    vector<int> a(n+1);
    vector<bool> l(n+1);
    rep(i,n) cin >> a[i+1];
    rep(i,n) l[i+1] = false;

    while(1){
        if(l[cur]) break;
        else{
            if(cur == 2) break;
            l[cur] = true;
            cur = a[cur];
            ans ++;
        }
    }

    if(cur == 2) cout << ans;
    else cout << -1;

    return 0;
}









