#include<iostream>
#include<vector>
using namespace std;

int main(){
    long N;
    long A;
    cin >> N >> A;
    vector<long> x;
    long tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        x.push_back(tmp);
    }
    long xs = 0;
    for(int i=0; i<N; i++){
        xs += x[i];
    }
    /*i枚目のカードまで見たときに 
    j枚使って合計がkとなる組み合わせ*/
    long dp[N+1][N+1][xs+1] = {};

    dp[0][0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N+1; j++){
            for(int k=0; k<xs+1; k++){
                dp[i+1][j][k] = dp[i][j][k];
                if( (j >= 1) && (k >= x[i]) ){
                    dp[i+1][j][k] += dp[i][j-1][k-x[i]];
                }
            }
        }
    }
    long ans = 0;
    for(int i=1;i<N+1; i++){
        if(A*i > xs){break;}
        ans += dp[N][i][A*i];
    }
    cout << ans << endl;
    return 0;
}