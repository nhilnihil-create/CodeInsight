#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,R;cin >> n >> m >> R;
    vector<int> r(R);
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    vector<vector<ll>> d(n,vector<ll>(n,inf));
    rep(i,n){
        d[i][i]=0;
    }
    rep(i,m){
        int a,b,c;cin >> a >> b >> c;
        a--,b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    rep(i,n){
        rep(j,n){
            rep(k,n){
                chmin(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    sort(r.begin(),r.end());
    int ans=inf;
    do{
        int res=0;
        rep(i,R-1){
            res+=d[r[i]][r[i+1]];
        }
        chmin(ans,res);
    }while(next_permutation(r.begin(),r.end()));
    cout << ans << endl;
}