#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define int long long
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

#define MAX_V 300
#define INF 1000000000000000
struct edge{int to, cost;};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s, int t){
    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(Pii(0, s));

    while(!que.empty()){
        Pii p = que.top(); que.pop();
        int v = p.second;
        if(v == t) return;
        if(d[v] < p.first) continue;
        REP(i, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(Pii(d[e.to], e.to));
            }
        }
    }
}

void add_edge(int from, int to, int cost){
    G[from].push_back(edge({to, cost}));
}


signed main(){

    int N;
    cin >> N;
    vector< pair<int, vector<int> > > A;
    int a;
    REP(i, N){
        REP(j, N){
            cin >> a;
            if(i < j){
                A.push_back(pair<int, vector<int> >(a, vector<int>({i, j})));
            }
        }
    }
    SORT(A);

    V = N;

    int ans = 0;
    REP(i, A.size()){
        int c = A[i].first;
        int s = A[i].second[0];
        int t = A[i].second[1];

        dijkstra(s, t);
        if(d[t] < c){
            cout << -1;
            return 0;
        }else if(d[t] > c){
            add_edge(s, t, c);
            add_edge(t, s, c);
            ans += c;
        }
    }

    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}