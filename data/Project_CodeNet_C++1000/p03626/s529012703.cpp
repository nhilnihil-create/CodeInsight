#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    long int mod = 1000000007;
    int n;
    scanf("%d", &n);
    char s[2][n];

    for (int i = 0; i < 2; i++){
        char row[n];
        scanf("%s", row);
        for (int j = 0; j < n; j++){
            s[i][j] = row[j];
        }
    } 
    // int m = 1;
    char nxt = s[0][0];
    long int ans;
    int state;
    if (s[0][0] == s[1][0]) {
        ans = 3;
        state = 1;
    }
    else {
        ans = 6;
        state = 2;
    }
    for (int i = 1; i < n; i++){
        if (nxt != s[0][i]){
            if (s[0][i] == s[1][i]){
                if (state == 1){
                    ans *= 2;
                    nxt = s[0][i];
                    state = 1;
                }
                else{
                    ans *= 1;
                    nxt = s[0][i];
                    state = 1;
                }
            }
            else{
                if (state == 1){
                    ans *= 2;
                    nxt = s[0][i];
                    state = 2;
                }
                else{
                    ans *= 3;
                    nxt = s[0][i];
                    state = 2;
                }
            }

        }
        ans %= mod;
        // cout << ans << "\n";
    }

    printf("%ld\n", ans);
}
