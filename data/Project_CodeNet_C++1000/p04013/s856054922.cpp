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
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    LL a;
    LL tmp;
    LL ans=0;
    cin >> n >> a;
    tmp=a;
    vector<LL> x(n);
    for(LL i=0; i<n; i++){
        cin >> x[i];
        tmp=max(tmp,x[i]);
    }

    tmp=tmp*n;

    vector<vector<vector<LL>>> dp(n+1, vector<vector<LL>>(n+1, vector<LL>(tmp+1)));

    for(LL i=0; i<=n; i++){
        for(LL j=0; j<=n; j++){
            for(LL k=0; k<=tmp; k++){
                //cout << i << " " << j << " " << k << endl;
                if(i==0 && j==0 && k==0){
                    dp[i][j][k]=1;
                }else if(i>=1 && k<x[i-1]){
                    dp[i][j][k]=dp[i-1][j][k];
                }else if(i>=1 && j>=1 && k>=x[i-1]){
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
                }else{
                    dp[i][j][k]=0;
                }
            }
        }
    }

    for(LL i=1; i<=n; i++){
        ans+=dp[n][i][i*a];
    }

    cout << ans << endl;

    return 0;
}
