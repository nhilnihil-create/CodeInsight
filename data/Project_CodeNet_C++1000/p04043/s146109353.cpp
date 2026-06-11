#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ceel(x, y) ((x) / (y) + !((x) % (y) == 0))
#define ff first
#define ss second
#define endl '\n'
#define print(v) for(auto x : v) cout << x << ' '; cout << endl;
#define debug(v) cout << #v << " = "; print(v);
#define printmp(v) for(auto x : v) cout << x.first << ' ' << x.second << endl; cout << endl;
using namespace std;
typedef long long int ll;
typedef long double ld;
void solve(){
    int a[3];
    for(int &x : a) cin >> x;
    sort(a , a + 3);
    if(a[0] == 5 && a[1] == 5 && a[2] == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}