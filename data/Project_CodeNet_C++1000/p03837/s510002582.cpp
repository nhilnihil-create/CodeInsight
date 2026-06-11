//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入
void warshall_floyd(vector<vector<long long>> &dist, vector<vector<long long>> &prev) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }
}

vector<int> get_path(const vector<vector<long long>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    vector<vector<ll>> prev(N,vector<ll>(N,INF));
    vector<vector<bool>> root(N,vector<bool>(N,true));
    int a,b,c;
    REP(i,M){
        cin >> a>>b>>c;
        a--;
        b--;
        dist[a][b]=c;
        dist[b][a]=c;
        prev[a][b]=a;
        prev[b][a]=b;
        root[a][b]=false;
        root[b][a]=false;
    }
    warshall_floyd(dist,prev);
    REP(i,N-1){
        REP2(j,i+1,N){
            vector<int> path=get_path(prev,i,j);
            
            REP(k,path.size()-1){
                root[path[k]][path[k+1]]=true;
                root[path[k+1]][path[k]]=true;
            }
        }
    }
    

    int cnt=0;
    REP(i,N-1){
        REP2(j,i+1,N){
            
            if(!root[i][j]){
                cnt++;
            } 
        }
    }
    cout<<cnt<<endl;
    
}