#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    long long int ans, i;
    if(s1[0] == s2[0]){
        ans = 3;
        i = 1;
    }
    if(s1[0] != s2[0]){
        ans = 3 * 2;
        i = 2;
    }

    while(i < n){
        if(s1[i-1] == s2[i-1]){
            ans *= 2;
            if(s1[i] == s2[i]) i += 1;
            else i += 2;
        }
        else if(s1[i-1] != s2[i-1]){
            if(s1[i] == s2[i]) i += 1;
            else{
                ans *= 3;
                i += 2;
            }
        }

        if(ans >= MOD) ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}