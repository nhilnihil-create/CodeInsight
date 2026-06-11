#include<iostream>
#include<vector>
using namespace std;
struct edge{long from,to,cost;};
long bellman_ford(int start){
    long n,m,a;
    cin>>n>>m;
    edge es[m];
    for(int i=0;i<m;i++){
        cin>>es[i].from>>es[i].to>>es[i].cost;
        es[i].from--;es[i].to--;es[i].cost*=-1;
    }
    vector<long>dist(n,0x7fffffffffffff);
    dist[start]=0L;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[es[j].to]>dist[es[j].from]+es[j].cost){
                dist[es[j].to]=dist[es[j].from]+es[j].cost;
            }
        }
    }
    
    bool f[n]={};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[es[j].from]==0x7fffffffffffff)continue;
            if(dist[es[j].to]>dist[es[j].from]+es[j].cost){
                dist[es[j].to]=dist[es[j].from]+es[j].cost;
                f[es[j].to]=true;
            }
            if(f[es[j].from]==true)f[es[j].to]=true;
        }
    }
    return f[n-1]?0x7fffffffffffff:dist[n-1];
}

int main(){
    long a=bellman_ford(0)*-1;
    if(a==0x7fffffffffffff*-1)cout<<"inf"<<endl;
    else cout<<a<<endl;
    return 0;
}