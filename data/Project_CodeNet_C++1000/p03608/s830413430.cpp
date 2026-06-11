#include<bits/stdc++.h>
using namespace std;
int dijkstra(int n,int s,int g,vector<vector<pair<int,int>>>&pas){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    int d[n];
    for(int i=0;i<n;i++)d[i]=1000000000;
    d[s]=0;
    while(q.size()){
        int p=q.top().second;
        if(p==g){
            return q.top().first;
        }
        q.pop();
        for(int i=0;i<pas[p].size();i++){
            if(d[p]+pas[p][i].second<d[pas[p][i].first]){
                d[pas[p][i].first]=d[p]+pas[p][i].second;
                q.push({d[pas[p][i].first],pas[p][i].first});
            }
        }
    }
}
int main(){
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    int t[r],a[m],b[m],c[m];
    int turn[r];
    for(int i=0;i<r;i++){
        scanf("%d",&t[i]);
        t[i]--;
        turn[i]=i;
    }
    vector<vector<pair<int,int>>>pas(n);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        pas[a[i]-1].push_back({b[i]-1,c[i]});
        pas[b[i]-1].push_back({a[i]-1,c[i]});
    }
    int shortest_way[r][r];
    for(int i=0;i<r-1;i++){
        for(int j=i+1;j<r;j++){
            shortest_way[i][j]=dijkstra(n,t[i],t[j],pas);
        }
    }
    int mi=1000000000;
    do{
        if(turn[0]>turn[r-1])continue;
        int dist=0;
        for(int i=0;i<r-1;i++){
            dist+=shortest_way[min(turn[i],turn[i+1])][max(turn[i],turn[i+1])];
            if(dist>=mi){
                break;
            }
        }
        mi=min(mi,dist);
    }while(next_permutation(turn,turn+r));
    printf("%d\n",mi);
    return 0;
}