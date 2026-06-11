#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N,A,x;
    cin >> N >> A;
    ll dp[N+1][6000];
    ll i,j;
    for(j=0;j<6000;j++){
        dp[0][j]=0;
    }
    dp[0][3000]=1;
    for(i=1;i<=N;i++){
        cin >> x;
        for(j=0;j<6000;j++){
            dp[i][j]=dp[i-1][j];
            if(j-x+A>=0&&j-x+A<6000)dp[i][j]+=dp[i-1][j-x+A];
        }
    }
    cout << dp[N][3000]-1 <<endl;
    return 0;
}
