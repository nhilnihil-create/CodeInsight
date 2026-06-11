#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005

int n ,m;
vector <int> adj[MAX_N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int a,b,i=0; i<m; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    deque <int> path{1};
    vector <bool> in_path(n+1);
    in_path[1] = 1;
    for(int ok=1; ok--; ){
        for(int&v : adj[path.back()])
            if(!in_path[v]){
                path.push_back(v);
                in_path[v] = 1;
                ok = 1;
                break;
            }
    }
    for(int ok=1; ok--; ){
        for(int&v : adj[path.front()])
            if(!in_path[v]){
                path.push_front(v);
                in_path[v] = 1;
                ok = 1;
                break;
            }
    }


    printf("%d\n",path.size());
    for(int&o : path)
        printf("%d ",o);
    printf("\n");
}
