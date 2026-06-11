#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;

int main(){
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    vector<vector<int>> dp(3001,vector<int>(3001,0));
    dp[0][0]=1;
    int s_max=(int)((double)f/100*e);
    for(int i=0;i<f+1;i++){
        for(int j=0;j<s_max+1;j++){
            if(i-100*a>=0) dp[i][j]=max(dp[i-100*a][j],dp[i][j]);
            if(i-100*b>=0) dp[i][j]=max(dp[i-100*b][j],dp[i][j]);
            if(i-c>=0&&j-c>=0) dp[i][j]=max(dp[i-c][j-c],dp[i][j]);
            if(i-d>=0&&j-d>=0) dp[i][j]=max(dp[i-d][j-d],dp[i][j]);
        }
    }
    ld ans=0;
    ld MAX=(ld)e/(100.0+(ld)e);
    int m_sum,m_s;
    for(int i=0;i<f+1;i++){
        for(int j=0;j<f/100*e+1;j++){
            if(dp[i][j]==1){
                ld s=(ld)j/(ld)i;
                if(s>=ans){
                    if(s>MAX) continue;
                    ans=s;
                    m_sum=i;
                    m_s=j;
                }
            }
        }
    }
    cout<<m_sum<<' '<<m_s<<endl;
}
 

