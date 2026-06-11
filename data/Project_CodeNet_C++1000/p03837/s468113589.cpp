#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    vector<vector<int>> d(n,vector<int>(n,inf));
    rep(i,n) d[i][i]=0;
    vector<int> a(m),b(m),c(m);
    rep(i,m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--,b[i]--;
        d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
    }
    rep(i,n) rep(j,n) rep(k,n) chmin(d[j][k],d[j][i]+d[i][k]);
    int ans=0;
    rep(i,m){
        bool f=true;
        rep(j,n){
            rep(k,n){
                if(d[j][k]==d[j][a[i]]+c[i]+d[b[i]][k]){
                    f=false;
                }
            }
        }
        if(f){
            ans++;
        }
    }
    cout << ans << endl;
}