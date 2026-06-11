#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003,INF=1<<30;

vector<int> S[MAX];
int visited[MAX][MAX],N;

int BFS(int u,int lim){
    
    for(int i=0;i<N;i++){
        visited[u][i]=INF;
    }
    
    visited[u][u]=0;
    
    queue<int> Q;
    Q.push(u);
    int cnt=1;
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        if(visited[u][a]>=lim) break;
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(visited[u][b]!=INF) continue;
            visited[u][b]=visited[u][a]+1;
            Q.push(b);
            cnt++;
        }
    }
    
    return cnt;
}

int BFS2(int u,int v,int lim,int when){
    
    for(int i=0;i<N;i++){
        visited[when][i]=INF;
    }
    
    visited[when][u]=0;
    visited[when][v]=0;
    
    queue<int> Q;
    Q.push(u);
    Q.push(v);
    
    int cnt=2;
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        if(visited[when][a]>=lim) break;
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(visited[when][b]!=INF) continue;
            visited[when][b]=visited[when][a]+1;
            Q.push(b);
            cnt++;
        }
    }
    
    return cnt;
}

int main(){
    
    int M;cin>>N>>M;
    vector<pair<int,int>> T(N-1);
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
        T[i]=make_pair(a,b);
    }
    
    if(M%2==0){
        int ans=INF;
        for(int i=0;i<N;i++){
            ans=min(ans,N-BFS(i,M/2));
        }
        cout<<ans<<endl;
    }else{
        int ans=INF;
        for(int i=0;i<N-1;i++){
            int a=T[i].first,b=T[i].second;
            ans=min(ans,N-BFS2(a,b,M/2,i));
        }
        
        cout<<ans<<endl;
    }
    
}


