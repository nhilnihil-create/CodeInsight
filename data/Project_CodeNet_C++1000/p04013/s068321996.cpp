#include<iostream>
#include<algorithm>
using namespace std;
typedef long long llong;

static const int MAX = 50;
llong dp[MAX + 1][MAX * MAX * 2 + 1];

int main(){
    int n, A;
    cin >> n >> A;

    int x[n + 1];
    int y;
    for (int i = 1; i <= n; i++){
        cin >> y;
        x[i] = y - A;
    }

    for (int i = 0; i <= n; i++){
        for (llong j = 0; j <= MAX * MAX * 2; j++){
            if ((i == 0) && (j == MAX * MAX)) dp[i][j] = 1;
            else if ((i > 0) && (((j - x[i]) < 0) || ((j - x[i]) > MAX * MAX * 2))) dp[i][j] = dp[i - 1][j];
            else if ((i > 0) && ((0 <= (j - x[i])) || ((j - x[i]) <= MAX * MAX * 2))) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - x[i]];
            else dp[i][j] = 0;
        }
    }

    cout << dp[n][MAX * MAX] - 1 << endl;

    return 0;
}