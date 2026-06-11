#include <cstdio>

const int MAXN=311, MAXM=311;

int N, M;
int A[MAXN][MAXM];
bool Vis[MAXM];
int Cnt[MAXM];

int main(){
	
	scanf("%d%d", &N, &M);
	
	for(int i=1;i<=M;++i)	Vis[i]=true;
	
	for(int i=1;i<=N;++i)	for(int j=1;j<=M;++j)	scanf("%d", &A[i][j]);
	
	int Ans=N;
	
	for(int i=1, x;i<=M;++i){
		for(int i=1;i<=M;++i)	Cnt[i]=0;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				if(Vis[A[i][j]]){
					++Cnt[A[i][j]];
					break;
				}
			}
		}
		x=0;
		for(int i=1;i<=M;++i){
			if(Cnt[i]>Cnt[x])	x=i;
		}
		if(Ans>Cnt[x])	Ans=Cnt[x];
		Vis[x]=false;
	}
	
	printf("%d\n", Ans);
	
	return 0;
}