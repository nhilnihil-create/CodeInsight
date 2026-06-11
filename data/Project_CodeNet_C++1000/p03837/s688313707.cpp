#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
int n, m;

struct Edge{
    /*辺の情報を入れる構造体で行き先とコストを表している*/
    //g[a].push_back(edge(b, c))みたいな感じでいれる
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> g[105];//edgeの配列でmax_vに対応するindexは各頂点のindex　それぞれのg[v]に対して複数のedgeが入っている
vector<vector<ll> > d(105, vector<ll>(105));//距離
vector<vector<pair<ll, int> > > costvec(105, vector<pair<ll, int> >(105));
vector<bool> use(1005, false);
 
void warshall_floyd(void){
    rep(k, n)rep(i, n)rep(j, n) {
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    }
}

int main(void){
    cin>>n>>m;
    rep(i, 105)rep(j, 105) d[i][j] = INF;
    rep(i, 105) d[i][i] = 0;
    rep(i, n)rep(j, n) costvec[i][j] = make_pair(INF, INF);
    rep(i, m){
        int a, b, c;
        cin>>a>>b>>c;
        --a;--b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
        d[a][b] = c;
        d[b][a] = c;
        costvec[a][b] = make_pair(c, i);
        costvec[b][a] = make_pair(c, i);
    }
    warshall_floyd();
    int ans = m;
    int now = 0;
    /*rep(i, n){
        rep(j, n){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }*/
    rep(k, n){
        rep(i, n)rep(j, n){
            if(d[k][i] == d[k][j] + costvec[i][j].first && use[costvec[i][j].second] == false){
                //cout<<i<<j<<k<<endl;
                now++;
                use[costvec[i][j].second] = true;
            }
        }
    }
    cout<<m-now<<endl;
    return 0;
}