#include <iostream>
#include <vector>
#define int long long
using namespace std;
int dp[55][55][2600]={};
vector<int> x;


signed main(){
    int n,a;
    cin>>n>>a;
    x.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<55;j++){
            for(int k=0;k<2600;k++){
                dp[i+1][j][k]+=dp[i][j][k];
                dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
            }   
        }
    }
    
    int ret=0;
    for(int j=0;j<51;j++){
        ret+=dp[n][j][a*j];
    }
    cout<<ret-1;
    return 0;
}

