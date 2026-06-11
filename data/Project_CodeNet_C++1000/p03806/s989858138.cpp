#include <bits/stdc++.h>

using namespace std;

struct pot {
    int a;
    int b;
    int c;
};

const int N = 45;
const int INF = 1e9 + 7;
int n, m, dp[N][N * 10][N * 10], Ma, Mb;
pot arr[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> Ma >> Mb;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].c = c;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n * 10; j++){
            for(int k = 0; k <= n * 10; k++){
                dp[i][j][k] = INF;
            }
        }
    }

    dp[1][arr[1].a][arr[1].b] = arr[1].c;
    dp[1][0][0] = 0;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n * 10; j++){
            for(int k = 0; k <= n * 10; k++){
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                if(j - arr[i].a >= 0 && k - arr[i].b >= 0){
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - arr[i].a][k - arr[i].b] + arr[i].c);
                }
            }
        }
    }
    int fmin = INF;
    for(int j = 1; j <= n * 10; j++){
        for(int k = 1; k <= n * 10; k++){
            int gc = __gcd(j, k);
            if(j / gc == Ma && k / gc == Mb){
                fmin = min(fmin, dp[n][j][k]);
            }
        }
    }
     if(fmin == INF){
        cout << -1 << '\n';
    } else {
        cout << fmin << '\n';
    }  
    return 0;
}