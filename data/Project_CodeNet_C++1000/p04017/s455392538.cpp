#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,a[100000],t,tot,dp[18][100000],x,y,L;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<18;i++)dp[i][n-1]=-1;
    cin>>m;
    t=0;
    for(int s=0;s<n-1;s++){
        while(t+1<n&&a[t+1]<=a[s]+m){
            t++;
        }
        if(t==n)dp[0][s]=-1;
        else dp[0][s]=t;
    }
    for(int i=1;i<18;i++){
        for(int j=0;j<n;j++){
            ll L=i;
            ll LL=j;
            for(int k=L-1;k>=0;k--){
                LL=dp[k][LL];
                if(LL==-1){dp[i][j]=-1;break;}
            }
            if(dp[i][j]==0)dp[i][j]=dp[0][LL];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        ll ans=0;
        cin>>x>>y;
        x--,y--;
        if(x>y)swap(x,y);
        while(1){
            if(dp[0][x]>=y||dp[0][x]==-1){
                cout<<ans+1<<endl;break;
            }
            for(int j=1;j<18;j++){
                if(dp[j][x]>=y||dp[j][x]==-1){
                    L=j;
                    break;
                }
            }
            //if(L==0){cout<<ans+1<<endl;break;}
            L--;
            x=dp[L][x];
            ans+=(1<<L);
        }
    }
}
