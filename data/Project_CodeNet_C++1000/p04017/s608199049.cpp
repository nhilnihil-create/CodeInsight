#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int lgn = 17;

int n,q,L;
int li[N+5];

int sparse[lgn+1][N+5];

void make_sparse(){
	for(int i=1;i<=lgn;i++){
		for(int j=1;j<=N;j++){
			sparse[i][j] = sparse[i-1][sparse[i-1][j]];
		}
	}
	return;
}

int find_day(int x, int y){
	int ret = 0;
	for(int i=lgn;i>=0;i--){
		if(sparse[i][x]<y){
			ret+=(1<<i);
			x = sparse[i][x];
		}
	}
	return ret+1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
	}
	scanf("%d",&L);
	scanf("%d",&q);
	int r = 1;
	for(int i=1;i<=n;i++){
		while(r <= n && li[r] - li[i] <= L) r++;
		sparse[0][i] = r-1;
	}
	make_sparse();
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		int ans = find_day(u,v);
		printf("%d\n",ans);
	}
	return 0;
}