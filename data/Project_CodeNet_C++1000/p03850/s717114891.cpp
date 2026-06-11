#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll PLUS=-1;
const ll MINUS=-2;

const ll INF=1e15;
int main(){
    int n;
    cin>>n;
    vector<ll> aop(n*2-1);
    for(int i=0;i<2*n-1;i++){
        string x;
        cin>>x;
        if(x=="+"){
            aop[i]=PLUS;
        }
        else if(x=="-"){
            aop[i]=MINUS;
        }
        else{
            aop[i]=stoi(x);
        }
    }
    vector<vector<ll>> dp(2*n,vector<ll>(3,-INF));
    dp[0][0]=0;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<3;j++){
            if(aop[i]==PLUS){
                dp[i+1][j]=dp[i][j];
            }
            else if(aop[i]==MINUS){
                if(j!=2) dp[i+1][j+1]=dp[i][j];
            }
            else{
                if(j%2){
                    for(int k=0;k<=j;k++){
                        dp[i+1][k]=max(dp[i+1][k],dp[i][j]-aop[i]);
                    }
                }
                else{
                    for(int k=0;k<=j;k++){
                        dp[i+1][k]=max(dp[i+1][k],dp[i][j]+aop[i]);
                    }
                }
                
            }
        }
    }
    cout<<dp[2*n-1][0]<<endl;
    return 0;
}