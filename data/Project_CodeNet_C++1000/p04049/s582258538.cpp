#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[2005];
int dist[2005];
int a[2005], b[2005];
queue<int> q;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n-1; i++){
        scanf("%d%d",&a[i],&b[i]);
        adjlist[a[i]].push_back(b[i]);
        adjlist[b[i]].push_back(a[i]);
    }
    int ans = n;
    if (k & 1){
        for (int i = 0; i < n-1; i++){
            memset(dist,-1,sizeof(dist));
            dist[a[i]] = dist[b[i]] = 0;
            q.push(a[i]); q.push(b[i]);
            while (q.size()){
                int u = q.front(); q.pop();
                for (auto v : adjlist[u]){
                    if (dist[v] == -1){
                        dist[v] = dist[u]+1;
                        q.push(v);
                    }
                }
            }
            int ct = 0;
            for (int j = 1; j <= n; j++){
                ct += (dist[j]>k/2);
            }
            ans = min(ans,ct);
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            memset(dist,-1,sizeof(dist));
            dist[i] = 0;
            q.push(i);
            while (q.size()){
                int u = q.front(); q.pop();
                for (auto v : adjlist[u]){
                    if (dist[v] == -1){
                        dist[v] = dist[u]+1;
                        q.push(v);
                    }
                }
            }
            int ct = 0;
            for (int j = 1; j <= n; j++){
                ct += (dist[j]>k/2);
            }
            ans = min(ans,ct);
        }
    }

    printf("%d ",ans);
}
