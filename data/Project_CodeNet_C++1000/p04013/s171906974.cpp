#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const ll INF=1e18;

int main(){
    int n,a;cin>>n>>a;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    ll dp[n+1][n+1][50*n+1];
    for(int i=0;i<=n;i++){
        for(int k=0;k<=n;k++){
            for(int s=0;s<=50*n;s++){
                dp[i][k][s]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int k=0;k<=n;k++){
            for(int s=0;s<=50*n;s++){
                dp[i+1][k][s]=dp[i][k][s];
                if(k>0&&s>=x[i]) dp[i+1][k][s]+=dp[i][k-1][s-x[i]];
            }
        }
    }
    ll sum=0;
  for(int k=1;k<=n;k++){
    sum+=dp[n][k][k*a];
  }
    cout<<sum<<endl;
    return 0;
}