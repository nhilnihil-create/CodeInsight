#include <bits/stdc++.h>
using namespace std;
int main() {
    int MOD = 1000000007;
    
    int N; string S, T;
    cin >> N >> S >> T;
    
    long long ans;
    char before;
    
    int i;
    if(S.at(0)==T.at(0)) {
        ans = 3;
        before = '|';
        i = 1;
    }
    else {
        ans = 6;
        before = '=';
        i = 2;
    }
    
    while (i<N) {
        if(S.at(i)==T.at(i)) {
            if(before=='=') ans *= 1;
            else ans *= 2;
            ans %= MOD;
            
            before = '|';
            i++;
        }
        else {
            if(before=='=') ans *= 3;
            else ans *= 2;
            ans %= MOD;
            
            before = '=';
            i+=2;
        }
    }
    
    cout << ans << endl;
}
