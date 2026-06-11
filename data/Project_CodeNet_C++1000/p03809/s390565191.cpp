#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

vector<int> rem(MAX),seen(MAX),G[MAX];

bool ok=true;

void DFS(int u,int p){
    
    if(G[u].size()==1){
        return;
    }
    
    int sum=0,maxi=0;
    
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i];
        if(a==p) continue;
        
        DFS(a,u);
        sum+=rem[a];
        maxi=max(rem[a],maxi);
    }
    
    int x=sum-rem[u];//子同士の回数
    if(x<0) ok=false;
    if(x>sum-maxi) ok=false;
    if(x*2>sum) ok=false;
    rem[u]-=x;
    return;
}

int main(){
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>rem[i];
    }
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    if(N==2){
        if(rem[0]==rem[1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else{
        
        for(int i=0;i<N;i++){
            if(G[i].size()>=2){
                DFS(i,-1);
                if(rem[i]!=0) ok=false;
                break;
            }
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}

