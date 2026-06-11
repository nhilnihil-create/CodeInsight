#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int const m = 10000;
    int n, a;
    cin >> n >> a;
    vector<int> x(n+1, 0);
    vector< vector<long long> > dp(n+1, vector<long long>(m*2, 0));
    for(int i=1;i<=n;i++){
        cin >> x[i];
        x[i] -= a;
    }
    dp[0][m] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m*2;j++){
            dp[i][j] = dp[i-1][j];
            if(x[i] <= j && j-x[i] < m*2) dp[i][j] += dp[i-1][j-x[i]];
        }
    }
    cout << dp[n][m]-1 << endl;
}
