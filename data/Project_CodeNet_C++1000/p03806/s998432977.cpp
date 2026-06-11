#include <bits/stdc++.h>
using namespace std;
int main(){
    const int inf=1000000;
    int N,Ma,Mb,ans=inf;
    cin>>N>>Ma>>Mb;
    vector<int> a(N),b(N),c(N);
    int dp[40+1][400+1][400+1];
    for(int i=0;i<N;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<10*N+1;j++){
            for(int k=0;k<10*N+1;k++){
                dp[i][j][k]=inf;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<10*N+1;j++){
            for(int k=0;k<10*N+1;k++){
              	if(dp[i][j][k]==inf) continue;	//ないとRE
                dp[i+1][j][k]=min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
            }
        }
    }
    for(int i=1;i<=10*N;i++){
        if(i*Mb/Ma>10*N) break;
      	if(i%Ma!=0) continue;
        ans=min(ans, dp[N][i][i*Mb/Ma]);
    }
    cout<<(ans==inf?-1:ans)<<endl;
}