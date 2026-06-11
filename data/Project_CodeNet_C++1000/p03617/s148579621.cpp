#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long Q, H, S, D;
    cin>>Q>>H>>S>>D;
    long N;
    cin>>N;
    long ans;
    if(N==1){
        ans = min(Q*4, min(H*2, S));
        cout<<ans<<endl;
    }
    else if(N==3){
        int dp[13];
        dp[0] = 0;
        dp[1] = Q;
        dp[2] = min(dp[0]+H, dp[1]+Q);
        dp[3] = min(dp[1]+H, dp[2]+Q);
        dp[4] = min(dp[0]+S, min(dp[2]+H, dp[3]+Q));
        dp[5] = min(dp[1]+S, min(dp[3]+H, dp[4]+Q));
        dp[6] = min(dp[2]+S, min(dp[4]+H, dp[5]+Q));
        dp[7] = min(dp[3]+S, min(dp[5]+H, dp[6]+Q));
        dp[8] = min(dp[0]+D, min(dp[4]+S, min(dp[6]+H, dp[7]+Q)));
        for(int i=9;i<13;++i){
            dp[i] = min(dp[i-8]+D, min(dp[i-4]+S, min(dp[i-2]+H, dp[i-1]+Q)));
        }
        cout<<dp[12]<<endl;
    }
    else if(N%2==0){
        ans = min(Q*(N*4), min(H*(N*2), min(S*N, D*(N/2))));
        cout<<ans<<endl;
    }
    else {
        ans = min(Q*((N-3)*4), min(H*((N-3)*2), min(S*(N-3), D*((N-3)/2))));
        int dp[13];
        dp[0] = 0;
        dp[1] = Q;
        dp[2] = min(dp[0]+H, dp[1]+Q);
        dp[3] = min(dp[1]+H, dp[2]+Q);
        dp[4] = min(dp[0]+S, min(dp[2]+H, dp[3]+Q));
        dp[5] = min(dp[1]+S, min(dp[3]+H, dp[4]+Q));
        dp[6] = min(dp[2]+S, min(dp[4]+H, dp[5]+Q));
        dp[7] = min(dp[3]+S, min(dp[5]+H, dp[6]+Q));
        dp[8] = min(dp[0]+D, min(dp[4]+S, min(dp[6]+H, dp[7]+Q)));
        for(int i=9;i<13;++i){
            dp[i] = min(dp[i-8]+D, min(dp[i-4]+S, min(dp[i-2]+H, dp[i-1]+Q)));
        }
        cout<<ans + dp[12]<<endl;
    }
}
