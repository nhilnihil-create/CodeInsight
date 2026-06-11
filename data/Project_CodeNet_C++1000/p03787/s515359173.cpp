#include <bits/stdc++.h>
    
using namespace std;

const int N = 1e5+15;

vector<int> adj[N];

int par[N];

int sz[N];

int find(int a){
    if(a==par[a])return a;
    return par[a]= find(par[a]);
}

void merge(int a,int b){
    a = find(a),b = find(b);
    if(a==b)return;
    par[b]= a;
    sz[a]+=sz[b];
}

int type[N];

int color[N];

int dfs(int x,int c){
    
    
    if(color[x]!=-1){
        if(color[x]!=c)return 1;

        return 0;
    }
    color[x]= c;
    
    int u,i,ret = 0;
    for(i=0;i<adj[x].size();++i){
        u = adj[x][i];

        ret |= dfs(u,c^1);
    }
    return ret;
}

int num[3];
int main(){

    int n,m,i,a,b;
    cin>>n>>m;

    for(i=1;i<=n;++i)par[i]= i,sz[i]= 1;
    for(i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        merge(a,b);
    }   

    vector<int> id;
    memset(color,-1,sizeof(color));

    
    for(i=1;i<=n;++i)
        if(find(i)==i)
            id.push_back(i);

    for(i=0;i<id.size();++i){
        a = id[i];
        
        if(sz[a]==1){
            type[a]= 0;
        }
        else {

            
            if(!dfs(a,0))
                type[a]= 1;
            else
                type[a]= 2;
        }
        ++num[type[a]];
    }       
    //0 --> sz1 , 1--> (0-1 graph) , 2--> cyle 포함하는 그래프
           
    
    
    long long ret = 0;
    
    for(i=0;i<id.size();++i){
        a = id[i];
            
        if(type[a]==0)
            ret+=n;
        else if(type[a]==1){

            ret+= (long long)sz[a]*num[0];

            ret+= (long long)num[1]*2;
            
            ret+= num[2];
        }   
        else{
            ret+= (long long)sz[a]*num[0];

            ret+= (long long)num[1] + num[2];
        }   
    }  
    cout<<ret<<endl;
}           
