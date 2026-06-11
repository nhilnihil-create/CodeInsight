#include <iostream>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const long INF = 1000000000005;

int main(){
    int N, M, R;
    cin >> N >> M >> R;

    int r[R];
    for(int i=0; i<R; i++){
        cin >> r[i];
        r[i]--;
    }

    long dp[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    sort(r, r+R);
    long ans = INF;
    do{
        long tans = 0;
        for(int i=1; i<R; i++){
            tans = tans + dp[r[i-1]][r[i]];
        }
        ans = min(ans, tans);
    }while(next_permutation(r, r+R));

    printf("%ld\n", ans);

    return 0;
}
