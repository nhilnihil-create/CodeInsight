#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=1234567;
const ll INF=1000000010;
const ll LINF=1000000000000000010LL;
const int MAX=500010;
const double EPS=1e-3;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
int main(){
    int n,k;cin>>n>>k;
    int a[5010];for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ng=0;int ok=n+1;
    while(ok-ng>1){
        bool dp[5010][5010]={false};
        int mid=(ng+ok)/2;
        int s=a[mid];
        a[mid]=0;
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]|=dp[i-1][j];
                if(j-a[i]>=0){
                    dp[i][j]|=dp[i-1][j-a[i]];
                }
            }
        }    
        bool f=false;
        for(int i=max(0,k-s);i<k;i++){
            f|=dp[n][i];
        }
        if(f){
            ok=mid;
        }else{
            ng=mid;
        }
        a[mid]=s;
    }
    cout<<ng<<endl;
    return 0;
}
