//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1<<30;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

//全2点間の距離をO(V^3)で求める、V:辺の数
//負の辺があっても大丈夫
in MAX_dist=2e16;
vector<vector<in>> d(0,vector<in>(0,MAX_dist));//d[x][y]:=x->yのcost,枝が無ければMAX_dist,ただし、d[i][i]=0

void warshall(){
    in V=d[0].size();
    rep(k,V)rep(i,V)rep(j,V) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n,m,r;
    cin>>n>>m>>r;
    vector<in> a(r,0);
    rep(i,r) cin>>a.at(i);
    d=vector<vector<in>>(n,vector<in>(n,MAX_dist));
    in x,y,z;
    rep(i,m){
        cin>>x>>y>>z;
        x--,y--;
        d[x][y]=z;
        d[y][x]=z;
    }
    rep(i,n) d[i][i]=0ll;
    warshall();
    vector<in> nex(r);
    rep(i,r) nex[i]=i;
    in ans=MAX_dist;
    in cop=0ll;
    do{
        cop=0ll;
        rep(i,r-1){
            cop+=d[a[nex.at(i)]-1ll][a[nex.at(i+1)]-1ll];
        }
        ans =min(ans,cop);
    }while(next_permutation(all(nex)));
    cout<<ans<<endl;
}