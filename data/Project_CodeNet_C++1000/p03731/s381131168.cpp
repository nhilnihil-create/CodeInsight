#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    int N,T;
    cin >> N>>T;
    vector<int> t(N);
    rep(i,N) cin >> t[i];

    int st = t[0]; ans =0;
    rep(i,N){
        if(st <= t[i]) {
             ans += T;
             st = t[i]+T;
    }
        else{
            ans += t[i]+T-st;
            st = t[i]+T;
        }      
}
 cout << ans << endl;
}