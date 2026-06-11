#include<bits/stdc++.h>
const int MOD = 1E9+7;
const int N = 100000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
vector<int> G[N];
int vis[N];
int main() {
	    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
 
    queue<int> Q;
    Q.push(1);
    Q.push(n);
    vis[1]=1;
    vis[n]=2;
 
    int fennec=0,snuke=0;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(int i=0;i<G[x].size();i++){
            int y=G[x][i];
            if(vis[y]==0){
                Q.push(y);
                vis[y]=vis[x];
                if(vis[y]==1)
                    fennec++;
                else if(vis[y]==2)
                    snuke++;
            }
        }
    }
    if(fennec>snuke)
        printf("Fennec\n");
    else
        printf("Snuke\n");
    return 0;
}