#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1009;
int n,m,d;
int mat[MAXN][MAXN];
int ans[MAXN][MAXN];
int ADD;

int cal(int x,int y){
	if(x%2==1){
		if(y%2==1)
			return 1;
		else
			return 2;
	}
	else{
		if(y%2==1)
			return 3;
		else
			return 4;
	}
}

int locx(int x,int y){
	if((x+y-1)%d==0){
		return (x+y-1)/d;
	}
	else
		return (x+y-1)/d+1;
}

int locy(int x,int y){
	if((y-x+m)%d==0)
		return (y-x+m)/d;
	else
		return (y-x+m)/d+1;
}

void COLOR(){
	int i,j;
	for(i=1;i<=(n+m)/d+1;i++){
		for(j=1;j<=(n+m)/d+1;j++){
			mat[i][j]=cal(i,j);
		}
	}
}

void REMAP(){
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			ans[i][j]=mat[locx(i,j)][locy(i,j)];
		}
	}
}

char GETCHAR(int x){
	if(x==1)return 'R';
	if(x==2)return 'G';
	if(x==3)return 'Y';
	if(x==4)return 'B';
}

void OUT(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%c",GETCHAR(ans[j][i]));
		}
		puts("");
	}
}

void solve(){
	COLOR();
	REMAP();
	OUT();
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	solve();
	return 0;
}