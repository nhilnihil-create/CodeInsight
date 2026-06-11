#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n,m;
    cin >> n >> m;
    long long mod = 1000000007;

    if(abs(n-m) >= 2){
        cout << 0 << endl;
        return 0;
    }
    else{
        if(abs(n-m) == 1){
            long long ans = 1;
            for(int i=1; i <= n; i++){
                ans *= i;
                ans %= mod;
            }
            for(int i=1; i <= m; i++){
                ans *= i;
                ans %= mod;
            }

            cout << ans << endl;
            return 0;
        }

        else{
            long long ans = 2;
            for(int i=1; i <= n; i++){
                ans *= i;
                ans %= mod;
            }
            for(int i=1; i <= m; i++){
                ans *= i;
                ans %= mod;
            }

            cout << ans << endl;
            return 0;
        }
    }
}
