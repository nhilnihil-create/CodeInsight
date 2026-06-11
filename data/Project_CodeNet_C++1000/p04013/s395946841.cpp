#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    int N,A;cin >> N >> A;
    vector<int> X(N);
    for(int i = 0;i < N;i++){
        cin >> X[i];
    }
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>((N+1),vector<ll>(2510)));
    for(int i = 0;i < N;i++){
        dp[i][0][0] = 1;
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < 2510;k++){
                if(k >= X[i]){
                    dp[i+1][j+1][k] += dp[i][j+1][k] + dp[i][j][k-X[i]];
                }else{
                    dp[i+1][j+1][k] += dp[i][j+1][k];
                }
            }
        }
    }
    /*for(int i = 1;i <= N;i++){
        for(int j = 0;j < 40;j++){
            cout << dp[N][i][j] << ' ';
        }
        cout << endl;
    }*/
    ll ans = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 1;j < 2510;j++){
            if(j % i == 0 && j / i == A){
                ans += dp[N][i][j];
            }
        }
    }
    cout << ans << endl;
}
