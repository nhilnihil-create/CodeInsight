#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

int main(){
    int N;
    int Ma, Mb;
    cin >> N >> Ma >> Mb;
    int a[N], b[N];
    int c[N];
    rep(i, N){
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[N + 1][401][401];//dp[i][a][b] : i番目までの薬品を見たとき，a[g],b[g]を達成するための最低コスト
    for(int i = 0;i <= N;++i){
        for(int aa = 0;aa <= 400;++aa){
            for(int bb = 0; bb <= 400;++bb){
                dp[i][aa][bb] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0;i < N;++i){
        for(int aa = 0;aa <= 400;++aa){
            for(int bb = 0; bb <= 400;++bb){
                dp[i + 1][aa][bb] = dp[i][aa][bb];
                if(a[i] <= aa && b[i] <= bb){
                    dp[i + 1][aa][bb] = min(dp[i][aa][bb], dp[i][aa - a[i]][bb - b[i]] + c[i]);
                }
            }
        }
    }
    int minv = INF;
    for(int aa = 1; aa <= 400;++aa){
        for(int bb = 1; bb <= 400;++bb){
            if(aa * Mb == Ma * bb){
                minv = min(dp[N][aa][bb], minv);
            }
        }
    }
    cout << ((minv == INF) ? -1 : minv) << endl;
}
