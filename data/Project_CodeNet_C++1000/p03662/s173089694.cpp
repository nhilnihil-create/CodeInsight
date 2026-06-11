#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge{
    int to;
    int cost;
    edge(int a, int b){
        to=a;
        cost=b;
    }
};
typedef pair<long long, int> P;
struct D{
    vector<edge> G[100008];
    long long d[100008],INF=1e18;
    void AddEdge(int from, int to, int cost){
        G[from].push_back(edge(to, cost));
    }
    void dijkstra(int n, int s){
        priority_queue<P, vector<P>, greater<P>> q;
        fill(d,d+n,INF);
        d[s]=0;
        q.push(P(0,s));
        while(!q.empty()){
            P p=q.top();
            q.pop();
            int v=p.second;
            if(d[v]<p.first)continue;
            for(int i=0;i<G[v].size();i++){
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    q.push(P(d[e.to],e.to));
                }
            }
        }
    }
};

int main(void){
    int n,f=0;
    D d,e;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        d.AddEdge(a,b,1);
        d.AddEdge(b,a,1);
        e.AddEdge(a,b,1);
        e.AddEdge(b,a,1);
    }
    d.dijkstra(n,0);
    e.dijkstra(n,n-1);
    for(int i=1;i<n-1;i++){
        if(d.d[i]<=e.d[i]){
            f++;
        }
    }
    if(f>n-2-f){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
}

