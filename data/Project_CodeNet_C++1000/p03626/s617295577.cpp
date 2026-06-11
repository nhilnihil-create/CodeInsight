#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
int n;
string s1, s2;

int memo[500][10][10] = {};

int dp(int i, int a, int b){
    if(i == n){
        return 1;
    }

    if(memo[i][a][b] != -1){
        return memo[i][a][b];
    }

    int ans = 0;

    if(s1[i] == s2[i]){
        for(int x = 1;x <= 3;x++){
            if(x != a && b != x){
                ans = (ans + dp(i+1, x, x)) % MOD;
            }
        }
    }else{
        for(int x = 1;x <= 3;x++){
            for(int y = 1;y <= 3;y++){
                if(x != y && x != a && y != b){
                    ans = (ans + dp(i+2, x, y)) % MOD;
                }
            }
        }

    }

    return memo[i][a][b] = ans;
}


signed main(){
    cin >> n;
    cin >> s1 >> s2;

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0, 0) << endl;


    return 0;
}

