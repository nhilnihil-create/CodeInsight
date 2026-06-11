#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    int dp[N][N];
    int v[N][N];
    const int INF = 1000000005;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = INF;
            v[i][j] = INF;
        }
        dp[i][i] = 0;
        v[i][i] = 0;
    }

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
        v[a][b] = c;
        v[b][a] = c;
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(v[i][j] == INF) continue;
            if(v[i][j] != dp[i][j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
