#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M, R;
    cin >> N >> M >> R;

    int r[R];
    for(int i=0; i<R; i++){
        cin >> r[i];
        r[i]--;
    }

    int dp[N][N];
    const int INF = 1000000005;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    sort(r, r+R);
    int ans = 1000000005;
    do{
        int t = 0;
        for(int i=1; i<R; i++){
            t += dp[r[i-1]][r[i]];
        }
        ans = min(ans, t);
    }while(next_permutation(r, r+R));

    cout << ans << endl;

    return 0;
}
