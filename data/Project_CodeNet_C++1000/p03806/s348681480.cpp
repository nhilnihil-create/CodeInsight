#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<int> a(n+1),b(n+1),c(n+1);
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    vector<vector<vector<int>>> dat(n+2,vector<vector<int>>(450,vector<int>(450,INF)));
    dat[1][0][0]=0;
    rep(i,n){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dat[i+1][j][k]=min(dat[i][j][k],dat[i+1][j][k]);
                dat[i+1][j+a[i]][k+b[i]]=min(dat[i][j][k]+c[i],dat[i+1][j+a[i]][k+b[i]]);
            }
        }
    }
    int ans=INF;
    rep(j,400){
        rep(k,400){
            if(j*mb==k*ma)
                ans=min(ans,dat[n+1][j][k]);
        }
    }
    if(ans==INF) cout<<"-1";
    else cout<<ans;
}