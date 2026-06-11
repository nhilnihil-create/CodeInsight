#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MaxN=1e5+5;

int N;
int A[MaxN],Deg[MaxN];

vector<int> To[MaxN];

void DFS(int u,int fa){
	int i,mx=0,cnt=0;
	LL x,sum=0;
	for(auto v:To[u])
		if(v^fa){
			DFS(v,u);
			cnt++;
			sum+=A[v];
			mx=max(mx,A[v]);
		}
	if(cnt){
		x=min(sum/2,sum-mx);
		if(A[u]>sum||sum-A[u]>x){
			puts("NO");
			exit(0);
		}
		A[u]-=sum-A[u];
	}
}

int main(){
	int i,u,v;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
	if(N<3){
		puts(A[1]^A[2]?"NO":"YES");
		return 0;
	}
	for(i=1;i<N;i++){
		scanf("%d%d",&u,&v);
		To[u].push_back(v);
		To[v].push_back(u);
		Deg[u]++,Deg[v]++;
	}
	for(i=1;i<=N;i++)
		if(Deg[i]>1){
			DFS(i,0);
			puts(A[i]?"NO":"YES");
			return 0;
		}
}