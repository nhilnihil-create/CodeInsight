#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
const int inf=1e+9;
int main(void){
    int n,m;cin>>n>>m;
    queue<tuple<int,int,int>> que;
    int d[n][n];
    rep(i,n)rep(j,n) d[i][j]=(i==j)? 0:inf;
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        d[a][b]=d[b][a]=c;
        que.push(make_tuple(a,b,c));
    }
    
    rep(k,n)rep(i,n)rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int res=m;
    rep(i,m){
        auto x=que.front();que.pop();
        int a,b,c;
        tie(a,b,c)=x;
        rep(j,n)rep(k,n){
            if(j==k)continue;
            if(d[j][a]+c+d[b][k]==d[j][k]){
                res--;
                goto skip;
            }
        }
        skip:
        continue;
    }
    cout<<res<<endl;
}
