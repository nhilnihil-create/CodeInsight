#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main (void){
    int N, A;
    cin >> N >> A;

    vector<int> x(N);

    for (int i = 0; i < N; i++){
        cin >> x.at(i);
        x[i] -= A;
    }

    sort(x.begin(), x.end());

    int X = 2 * N * max(A, x[N-1]-A);

    long long dp[N][X];

    for (int j = 0; j < X; j++){
        if (j == x[0] + X/2){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = 0;
        }
    }

    dp[0][X/2] += 1;

    for (int i = 1; i < N; i++){
        for (int j = 0; j < X; j++){
                dp[i][j] = dp[i-1][j];
            }
        for (int j = 0; j < X; j++){
            for (int k = 0; k < X; k++){
                if (k + x[i] == j){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }

    cout << dp[N-1][X/2] - 1 << endl;

	return 0;
}