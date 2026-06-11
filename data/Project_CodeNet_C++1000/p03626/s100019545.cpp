#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    ll ans = 1LL;
    int from = -1; // 前が縦なら1
    for(int i = 0; i < n; ){
        if(s1[i] == s2[i]){ // 縦
            if(i == 0){
                ans *= 3;
            }else{
                if(from) ans *= 2;
            }
            from = 1;
            i += 1;
        }else{              // 横
            if(i == 0){
                ans *= 6;
            }else{
                if(from) ans *= 2;
                else ans *= 3;
            }
            from = 0;
            i += 2;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
