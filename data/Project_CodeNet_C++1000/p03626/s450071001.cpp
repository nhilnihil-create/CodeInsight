#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

void solve();

int main(void){
    int N; string s1, s2;
    cin >> N >> s1 >> s2;

    if(N == 1) cout << 3 << endl;
    else{
        ll ans = 1;
        int MOD = 1000000007;
        bool all_tate = true;
        rep(i, N){
            if(s1[i] != s2[i]) all_tate = false;
        }
        if(all_tate){
            rep(i, N){
                if(i == 0) ans = 3;
                else ans = (ans << 1) % MOD;
            }
        }
        else{
            rep(i, N){
                if(i == 0){
                    if(s1[i] == s2[i]) ans = 3;
                    else{
                        ans = 6;
                        i++;
                    }
                }
                else{
                    // AX
                    // AX この時は*2
                    // AAX
                    // BBX この時は*1
                    // AXX
                    // AYY この時は*2してi++
                    // AAXX
                    // BBYY この時は*3してi++
                    if(s1[i-1] == s2[i-1]) ans = (ans << 1) % MOD;
                    else if(s1[i] != s2[i]) ans = (ans * 3) % MOD;

                    if(s1[i] != s2[i]) i++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

void solve(){}