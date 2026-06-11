#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
const int64_t INF = 1e15;
const int64_t cut_off = 8*1e14;

int main(){
    int N;
    int64_t A[100010];
    char op[100010];
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        if(i!=N){
            cin>>op[i];
        }
    }
    int64_t dp[3][100010]={};
    for(int i=0;i<100010;i++){
        for(int j=0;j<3;j++){
            dp[j][i]=INF;
        }
    }
    dp[0][1]=A[1];
    for(int i=1;i<=N-1;i++){
        if(op[i]=='-'){
            if(dp[1][i]<cut_off){
                if(dp[2][i]<cut_off){
                    dp[2][i+1]=max(dp[2][i],dp[1][i])+A[i+1];
                }else{
                    dp[2][i+1]=dp[1][i]+A[i+1];
                }
            }
            dp[0][i+1]=dp[0][i]-A[i+1];
            dp[1][i+1]=dp[0][i]-A[i+1];
        }else{
            dp[0][i+1]=dp[0][i]+A[i+1];
            dp[1][i+1]=dp[1][i]-A[i+1];
            dp[2][i+1]=dp[2][i]+A[i+1];
        }
    }
    int64_t res = -INF;
    for(int i=0;i<3;i++){
        if(dp[i][N]<cut_off){
            res = max(res,dp[i][N]);
        }
    }
    cout<<res<<endl;
    
    return 0;
}
