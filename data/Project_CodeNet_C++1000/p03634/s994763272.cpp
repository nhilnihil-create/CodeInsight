#include<iostream>
#include<vector>
using namespace std;

struct edge{
    long long to;
    long long cost;
};

long long val[100001];
vector<edge> G[100001];

void dfs(long long v, long long dep){
    val[v]=dep;
    long long i;
    for(i=0; i<G[v].size(); i++){
        if(val[G[v][i].to]<0){
            dfs(G[v][i].to,dep+G[v][i].cost);
        }
    }
}

int main(){
    //input
    long long N;
    cin >> N;
    long long a,b,c;
    long long i;
    for(i=1; i<=N-1; i++){
        cin >> a >> b >> c;
        edge e = {b,c};
        G[a].push_back(e);
        edge f = {a,c};
        G[b].push_back(f);
    }
    long long Q, K;
    cin >> Q >> K;
    long long x[Q+1], y[Q+1];
    for(i=1; i<=Q; i++){
        cin >> x[i] >> y[i];
    }

    //calc
    for(i=1; i<=N; i++){
        val[i]=-1;
    }
    dfs(K,0);

    //answer
    for(i=1; i<=Q; i++){
        cout << val[x[i]]+val[y[i]] << endl;
    }
    system("pause");
    return 0;
}