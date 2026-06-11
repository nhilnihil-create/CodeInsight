#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int K, S, ans = 0;
    cin >> K >> S;
    rep(i, K + 1)
        rep(j, K + 1)
            if(0 <= S - i - j && S - i - j <= K) ans++;
    cout << ans << endl;
}