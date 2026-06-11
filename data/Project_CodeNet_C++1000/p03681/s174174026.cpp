#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;


int main() {

    ll n,m; cin >> n >> m;
    ll ans = 1;
    if(n == m){
        for(int i = 1; i <= n; i ++){
            ans = (ans*i)%1000000007;
        }
        for(int i = 1; i <= m; i ++){
            ans = (ans*i)%1000000007;
        }
        cout << (ans*2)%1000000007;
    }else if(abs(n-m) == 1){
        for(int i = 1; i <= n; i ++){
            ans = (ans*i)%1000000007;
        }
        for(int i = 1; i <= m; i ++){
            ans = (ans*i)%1000000007;
        }
        cout << ans%1000000007;
    }else{
        cout << 0;
    }
    return 0;
}
