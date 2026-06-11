#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;



int main(){
    int n;cin >> n;
    char c[n-1];
    int a[n];
    for (int i = 0; i < 2*n-1; i++) {
        if(i%2==0) cin >> a[i/2];
        else cin >> c[i/2];
    }
    LL dp[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j]=-LINF;
        }
    }
    dp[0][0]=a[0];
    for (int i = 0; i < n-1; i++) {
        if(c[i]=='+'){
            dp[i+1][0]=max(dp[i][0]+a[i+1],dp[i][1]+a[i+1]);
            dp[i+1][1]=dp[i][1]-a[i+1];
            dp[i+1][2]=dp[i][2]+a[i+1];
        }
        else{
            dp[i+1][1]=dp[i][0]-a[i+1];
            dp[i+1][2]=max(dp[i][2]+a[i+1],dp[i][1]+a[i+1]);
        }
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;
    return 0;
}


