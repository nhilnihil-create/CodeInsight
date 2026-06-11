#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
struct Que{
    int v;
    int d;
    int c;
};

vector<int> S[MAX];
int N,color[MAX],dis[MAX];//iからdis[i]までの距離はもうみた

void BFS(int v,int d,int c){
    queue<pair<int,int>> q;
    if(d<=dis[v]) return;
    if(color[v]==0) color[v]=c;
    dis[v]=d;
    q.push(make_pair(v,dis[v]));
    while(!q.empty()){
        int a=q.front().first,b=q.front().second;
        q.pop();
        for(int i=0;i<S[a].size();i++){
            int e=S[a][i];
            if(b-1<=dis[e]) continue;
            if(color[e]==0) color[e]=c;
            dis[e]=b-1;
            q.push(make_pair(e,dis[e]));
            //cout<<dis[e];
        }
    }
}

int main(){

  int M,Q;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        color[i]=0;
        dis[i]=-1;
    }
    
    cin>>Q;
    vector<Que> T(Q);
    
    for(int i=0;i<Q;i++){
        cin>>T[i].v>>T[i].d>>T[i].c;
        T[i].v--;
    }
    
    for(int i=Q-1;i>=0;i--){
        BFS(T[i].v,T[i].d,T[i].c);
        
        /*for(int j=0;j<N;j++){
            cout<<color[j]<<endl;
        }*/
    }
    
    for(int i=0;i<N;i++){
        cout<<color[i]<<endl;
    }
}

