#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> l(2 * n);
    rep(i, 2 * n){
        cin >> l[i];
    }
    ll ans = 0;
    sort(l.begin(), l.end());
    for(int i = 0; i < 2 * n; i += 2){
        ans += l[i];
    }
    cout << ans << endl;
}