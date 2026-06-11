#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1e9 + 7;

int main(){
    int N; cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    bool pre = 0;
    ll ans = 1;
    rep(i, 0, N){
        ans %= MOD;
        if(i == 0){
            if(S1[i] == S2[i]){
                ans *= 3;
                pre = 0;
            }else{
                i++;
                ans *= 6;
                pre = 1;
            }
            continue;
        }
        if(S1[i] == S2[i]){
            if(pre == 1){
                ans *= 1;
            }else{
                ans *= 2;
            }
            pre = 0;
        }else{
            i++;
            if(pre == 1){
                ans *= 3;
            }else{
                ans *= 2;
            }
            pre = 1;
        }
    }
    ans %= MOD;
    cout << ans << endl;
}