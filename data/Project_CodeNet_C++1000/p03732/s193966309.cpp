#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MOD 998244353
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL N;
    LL W;
    cin >> N >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    for(LL i=0; i<N; i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<vector<LL>>> dp(3*N+1, vector<vector<LL>>(N+1, vector<LL>(N+1, 0)));
    for(LL i=1; i<=N; i++){
        for(LL j=1; j<=i; j++){
            for(LL k=0; k<=3*N; k++){
                dp[k][j][i]=dp[k][j][i-1];
                if(w[i-1]-w[0]>k){
                    continue;
                }
                if(j*w[0]+k>W){
                    continue;
                }
                dp[k][j][i]=max(dp[k][j][i], dp[k-(w[i-1]-w[0])][j-1][i-1]+v[i-1]);
                //if(i==2){
                //    cout << v[i] << " " << dp[k][j][i] << endl;
                //}
            }
        }
    }

    LL ans=0;
    for(LL i=0; i<=N; i++){
        for(LL j=0; j<=3*N; j++){
            ans=max(ans, dp[j][i][N]);
        }
    }

    cout << ans << endl;

    return 0;
}
