#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-3;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
bool dp[5010][5010];
int main(){
    int n,k;cin>>n>>k;
    ll a[5010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ok=0;int ng=n+1;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        int s=a[mid];a[mid]=0;
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
        bool ans=false;
        for(int i=max(0,k-s);i<k;i++){
            ans|=dp[n][i];
        }
        a[mid]=s;
        if(ans){
            ng=mid;
        }else{
            ok=mid;
        }
    }
    cout<<ok<<endl;
    return 0;
}
