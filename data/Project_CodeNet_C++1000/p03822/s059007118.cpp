#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+5;

int N;
int F[MaxN];

vector<int> To[MaxN];

void DFS(int u){
	int i=0;
	for(auto v:To[u])
		DFS(v);
	sort(To[u].begin(),To[u].end(),[](int a,int b){return F[a]>F[b];});
	for(auto v:To[u])
		F[u]=max(F[u],F[v]+(++i));
}

int main(){
	int i,fa;
	scanf("%d",&N);
	for(i=2;i<=N;i++){
		scanf("%d",&fa);
		To[fa].push_back(i);
	}
	DFS(1);
	printf("%d\n",F[1]);
	return 0;
}