#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

ll dp[60][60][4000];

int main(){
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    
    // 組み合わせの公式（パスカルの三角形）
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= N * 50; k++){
                if(i == 0 && j == 0 && k == 0){
                    dp[i][j][k] = 1;
                }
                else if(i >= 1 && k < x[i - 1]){
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else if(i >= 1 && j >= 1 && k >= x[i - 1]){
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i - 1]];
                }
                else{
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= N; j++){
    //         cout << i << " " << j << endl;
    //         for(int k = 0; k <= (i + 1) * A; k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ans += dp[N][i][i * A];
        // cout << dp[N][i][i * A] << " ";
    }
    // cout << endl;
    
    cout << ans << endl;
}