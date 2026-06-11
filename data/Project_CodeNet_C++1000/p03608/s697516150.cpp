#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll inf=1e9;
int main(void){
    int n,m,R;cin>>n>>m>>R;
    vector<int> r(R);
    rep(i,R){
        cin>>r[i];
        r[i]--;
    }
    sort(r.begin(),r.end());
    vector<vector<ll>> t(n,vector<ll>(n,inf));
    rep(i,m){
        int a,b;ll c;cin>>a>>b>>c;a--;b--;
        t[a][b]=t[b][a]=c;
    }
    rep(i,n)t[i][i]=0;
    rep(k,n)rep(i,n)rep(j,n)chmin(t[i][j],t[i][k]+t[k][j]);
    ll res=1e18;
    do{
        ll buf=0;
        rep(i,R-1)buf+=t[r[i+1]][r[i]];
        chmin(res,buf);
    }while(next_permutation(r.begin(),r.end()));
    cout<<res<<endl;
}