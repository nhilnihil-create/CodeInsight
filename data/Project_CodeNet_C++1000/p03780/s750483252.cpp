#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int n,k;
vector<int> a;
// dp[i][j]:=i番目まで使って和jが実現できる
bool dp[5010][5010];
bool DP(int index){
    rep(i,5010)rep(j,5010) dp[i][j]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(i-1==index) continue;
            if(j-a[i-1]>=0) dp[i][j]=dp[i-1][j-a[i-1]];
        }
    }
    // cout<<a[index]<<endl;
    // rep(j,k+1){
    //     printf("(%d):%d\n",j,dp[n][j]);
    // }
    for(int i=max(k-a[index],0);i<k;i++){
        if(dp[n][i]) return true;
    }
    return false;
}
int main(){
    cin>>n>>k;
    rep(i,n){
        int aa; cin>>aa;
        a.push_back(aa);
    }
    sort(all(a));
    int l=-1,r=n,ans=0;
    while(abs(r-l)>1){
        // cout<<l<<" "<<r<<endl;
        if(!DP((r+l)/2)){
            l=(r+l)/2;
            ans=l+1;
        }
        else r=(r+l)/2;
    }
    cout<<ans<<endl;
    return 0;
}
