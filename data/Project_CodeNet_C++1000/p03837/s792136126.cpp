#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define MOD 998244353
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
struct edge{//グラフに使うヤツ
    ll from,to,cost;
};
typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

ll n,m;
vector<vector<edge> > graph;
ll dp[105][105];
bool used[105][105];

void warshall_floyd(){
    for (ll k=0;k<n;k++){
        for (ll i=0;i<n;i++){
            for (ll j=0;j<n;j++){
                if (dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
}

vector<edge> dist;

int main() {
    cin >> n >> m;
    graph=G(n);
    for (ll i=0;i<n;i++){
        for (ll j=0;j<n;j++){
            if (i==j){
                dp[i][j]=0;
            }else{
                dp[i][j]=INF;
            }
        }
    }
    for (ll i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        dp[a][b]=c;
        dp[b][a]=c;
        edge e;
        e.from=a;
        e.to=b;
        e.cost=c;
        dist.push_back(e);
        e.from=b;
        e.to=a;
        e.cost=c;
        dist.push_back(e);
    }
    warshall_floyd();
    ll ans=0;
    for (ll i=0;i<dist.size();i++){
        bool flag=false;
        for (ll j=0;j<n;j++){
            for (ll k=0;k<n;k++){
                if (dp[j][dist[i].from]+dist[i].cost+dp[dist[i].to][k]==dp[j][k]){
                    flag=true;
                }
            }
        }
        if (!(flag)){
            ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}

