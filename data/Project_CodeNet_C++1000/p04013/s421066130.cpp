#include<iostream>
using namespace std;
int main(){
    int n,a,c;
    cin>>n>>a;
    long x[n],dp[n][5001];
    for(int i=0;i<n;i++){cin>>c;x[i]=c-a;}
    dp[0][2500]++;dp[0][2500+x[0]]++;
    for(int i=1;i<n;i++)for(int j=0;j<5001;j++)dp[i][j]=dp[i-1][j]+(0<=j-x[i]&&j-x[i]<=5000?dp[i-1][j-x[i]]:0L);
    cout<<dp[n-1][2500]-1L<<endl;
    return 0;
}