#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, dp[N][2], score[N]; //0 rock, 1 paper
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s;
    n = s.length();

    if(s[0] == 'g'){
        dp[1][0] = 1;
        dp[1][1] = 0;
        score[1] = 0;
    } else {
        dp[1][0] = 1;
        dp[1][1] = 0;
        score[1] = 0;
    }

    for(int i = 2; i <= n; i++){
        if(s[i - 1] == 'g'){
            if(dp[i - 1][1] + 1 <= dp[i - 1][0]){
                score[i] = score[i - 1] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
                score[i] = score[i - 1];
            }
        } else {
            if(dp[i - 1][1] + 1 <= dp[i - 1][0]){
                score[i] = score[i - 1];
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
                score[i] = score[i - 1] - 1;
            }
        }
    }
    cout << score[n] << '\n';
    return 0;
}