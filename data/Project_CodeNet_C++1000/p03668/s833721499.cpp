#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003;
const ll INF=1LL<<60;
vector<int> G[MAX];

int DFS(int u,int p){
    int gru=0;
    
    for(int to:G[u]){
        if(to==p) continue;
        gru^=(DFS(to,u)+1);
    }
    
    return gru;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int a=DFS(0,-1);
    
    if(a) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

