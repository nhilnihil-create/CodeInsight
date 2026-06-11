#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;
int n,m,r,ans=INF;
vector<int>v,a,b,c;
int dp[205][205];

void dfs(vector<int>x){
    if(x.size()==r){
        int calc=0;
        rep(i,r-1){
            calc+=dp[x[i]][x[i+1]];
        }
        ans=min(ans,calc);
        return;
    }
    x.push_back(-1);
    rep(i,r){
        if(count(x.begin(),x.end(),v[i])==0){
            x.back()=v[i];
            dfs(x);
        }
    }
}

int main(){
    cin>>n>>m>>r;
    v=vector<int>(r);
    a=b=c=vector<int>(m);
    rep(i,r){
        cin>>v[i];
        v[i]--;
    }
    //WF初期化
    rep(i,205)rep(j,205)dp[i][j]=INF;
    rep(i,205)dp[i][i]=0;
    rep(i,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--; b[i]--;
        dp[a[i]][b[i]]=c[i];
        dp[b[i]][a[i]]=c[i];
    }
    //WF
    rep(k,n)rep(i,n)rep(j,n){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    dfs(vector<int>());
    cout<<ans<<endl;
}