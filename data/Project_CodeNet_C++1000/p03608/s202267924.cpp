//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m,r,ans=inf; cin>>n>>m>>r;
    vector<vector<int>> d(n,vector<int>(n,inf));
    vector<int> ro(r,0),p(r,0);
    rep(i,n) d[i][i]=0;
    rep(i,r){
        cin>>ro[i]; ro[i]--;
        p[i]=i+1;
    }
    sort(al(ro));
    rep(i,m){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        d[b][a]=d[a][b]=c;
    }
    rep(k,n)rep(i,n)rep(j,n){
        if(d[i][j]>d[i][k]+d[k][j])
        d[i][j]=d[i][k]+d[k][j];
    }
    do{
        int cnt=0;
        rep(i,r-1) cnt+=d[ro[p[i]-1]][ro[p[i+1]-1]];
        ans=min(ans,cnt);
    }while(next_permutation(al(p)));
    cout<<ans<<endl;
}