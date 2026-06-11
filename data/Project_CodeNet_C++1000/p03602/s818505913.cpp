#include<bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n) for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 1050000000;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

int A[300][300];

struct edge{ int to, cost;};
typedef pair<LL, int> P;

int V;
vector<edge> G[300];
LL d[300];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    REP(i, 300){ d[i] = INFL; }
    d[s] = 0;
    que.push(P(0LL, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first){ continue; }
        REP(i, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, PII> > vec;
    REP(i, N){
        REP(j, N){
            int tmp;
            cin >> tmp;
            A[i][j] = tmp;
            if(i < j){
                vec.PB(MP(tmp, MP(i,j)));
            }
        }
    }

    sort(ALL(vec));
    REP(i, vec.size()){
        int now_cos = vec[i].first;
        int s = vec[i].second.first;
        int t = vec[i].second.second;
        dijkstra(s);
        if(d[t] < now_cos){
            cout << -1 << endl;
            return 0;
        }else if(d[t] > now_cos){
            edge e1,e2;
            e1.to = t;
            e1.cost = now_cos;
            G[s].PB(e1);
            e2.to = s;
            e2.cost = now_cos;
            G[t].PB(e2);
        }
    }

    LL ans = 0;
    REP(i, N){
        REP(j, G[i].size()){
            ans += G[i][j].cost;
        }
    }

    cout << ans / 2 << endl;
}
