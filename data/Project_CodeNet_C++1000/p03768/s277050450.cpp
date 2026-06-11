#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

vector<int> edge[100050];
int color[100050];
int painted[100050];

void DFS(int V,int dis,int paint){
    if(painted[V]>=dis || dis<0) return;
    painted[V]=dis;
    if(color[V]==0) color[V]=paint;
    rep(i,edge[V].size()) DFS(edge[V][i],dis-1,paint);
}

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    rep(i,N) painted[i]=-1;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--,b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int Q;
    cin >> Q;
    int v[Q],d[Q],c[Q];
    reprev(i,Q){
        scanf("%d%d%d",&v[i],&d[i],&c[i]);
        v[i]--;
    }
    rep(i,Q){
        DFS(v[i],d[i],c[i]);
    }
    rep(i,N) printf("%d\n",color[i]);
}
