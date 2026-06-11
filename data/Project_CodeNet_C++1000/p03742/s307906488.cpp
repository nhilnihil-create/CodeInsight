#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


void solve(long long X, long long Y){
    if (abs(X - Y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout <<"Alice" << endl;
    }
}

signed main(){
//    vector<vector<char>> dp(30, vector<char>(30));
//    for(int i = 0; i < 30; ++i) {
//        for(int j = 0; j <= i; ++j) {
//            int k = i - j;
//            dp[j][k] = 'L';
//            for(int l = 1; 2 * l <= j; ++l) {
//                if (dp[j - 2 * l][k + l] == 'L') {
//                    dp[j][k] = 'W';
//                }
//            }
//            for(int l = 1; 2 * l <= k; ++l) {
//                if (dp[j + l][k - 2 * l] == 'L') {
//                    dp[j][k] = 'W';
//                }
//            }
//        }
//    }
//    printf("   ");
//    for(int i = 0; i < 24; ++i) {
//        printf("%3lld", i);
//    }
//    cout << endl;
//    for(int i = 0; i < 30; ++i) {
//        printf("%3lld", i);
//        for(int j = 0; j < 24; ++j) {
//            printf("%3c", dp[i][j]);
//        }
//        printf("\n");
//    }
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(X, Y);
    return 0;
}