#include <bits/stdc++.h>

#define lint long long

lint MOD = 1000000007;

using namespace std;

int main(){
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    
    lint ans = 1;
    int state;
    int pos = 0;
    
    if(S1[0] == S2[0]){
        ans *= 3;
        pos = 1;
    } else {
        ans *= 6;
        pos = 2;
    }
    
    while(pos < N){
        if(S1[pos-1] == S2[pos-1]){
            if(S1[pos] == S2[pos]){
                ans *= 2;
                pos++;
            } else {
                ans *= 2;
                pos += 2;
            }
        } else {
            if(S1[pos] == S2[pos]){
                ans *= 1;
                pos++;
            } else {
                ans *= 3;
                pos += 2;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
    
}




