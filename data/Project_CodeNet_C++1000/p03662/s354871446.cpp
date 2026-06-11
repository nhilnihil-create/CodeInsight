#include <bits/stdc++.h>

using namespace std;

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)
#define SCANFD(x) scanf("%d",&x)

int main(){
    int N;
    int a,b;
    int ress,resf;
    int dists[100001],distf[100001];
    queue<int> q;
    vector<int> g[100001];

    for(int i=0;i<100001;i++){
        dists[i] = -1;
        distf[i] = -1;
    }
    scanf("%d",&N);
    distf[1] = 0;
    dists[N] = 0;
    
    for(int i=0;i<N-1;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    q.push(1);

    while(q.size()>0){
        int n = q.front();
        q.pop();
        for(auto itr =g[n].begin();itr!=g[n].end();itr++){            
            if(distf[*itr]==-1){
                distf[*itr] = distf[n]+1;
                q.push(*itr);
            }
        }
        
    }

    q.push(N);

    while(q.size()>0){
        int n = q.front();
        q.pop();
        for(auto itr =g[n].begin();itr!=g[n].end();itr++){
            if(dists[*itr]==-1){
                dists[*itr] = dists[n]+1;
                q.push(*itr);
            }
        }
    }
    ress = 0;
    resf = 0;
    for(int i=1;i<=N;i++){
        if(dists[i]>=distf[i])
            resf++;
        else
            ress++;
    }
    

    if(ress<resf)
        printf("Fennec\n");
    else
        printf("Snuke\n");

    return 0;
}
