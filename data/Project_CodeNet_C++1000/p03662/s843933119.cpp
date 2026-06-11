#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAX=109999;
const ll INF=0x3f3f3f3f3f3f3f;
vector<int> conn[MAX];
queue<pii> bfs;
int n,m,chk[MAX],c[2];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    bfs.push(make_pair(1,0)); bfs.push(make_pair(n,1));
    while(!bfs.empty()){
        pii tmp=bfs.front();
        bfs.pop();
        if(chk[tmp.x]==0) {
            chk[tmp.x]=1; c[tmp.y]++;
            for(int i=0;i<conn[tmp.x].size();i++) if(chk[conn[tmp.x][i]]==0) bfs.push(make_pair(conn[tmp.x][i],tmp.y));
        }
    }
    if(c[0]>c[1]) printf("Fennec\n");
    else printf("Snuke\n");
}
