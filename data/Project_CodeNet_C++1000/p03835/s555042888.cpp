#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    long long k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x,k+1){
        rep(y,k+1){
            int z = s - x - y;
            if( 0 <= z && z <= k ) ans++;
        }
    }
    cout << ans << endl;
}