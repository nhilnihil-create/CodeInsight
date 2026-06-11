#include<bits/stdc++.h>
#define rep(i, k, n) for (int i = (int) (k); i < (int) (n); i++)
using namespace std;

int main(){
    string S;
    cin >> S;
    long ans = 0, n = S.length();
    rep(bit, 0, (1<<(n - 1))){
        long m = S[0] - '0';
        rep(i, 1, n){
            if(bit & (1<<(i - 1))){
                ans += m;
                m = S[i] - '0';
            }else{
                m = m * 10 + (S[i] - '0');
            }
        }
        ans += m;
    }
    
    cout << ans << endl;
    
    return 0;
}