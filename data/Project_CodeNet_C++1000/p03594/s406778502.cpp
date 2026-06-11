#include<bits/stdc++.h>

using namespace std;

#define N 3000
int n,m,d;
const char f[2][2]={'R','Y','G','B'};

char calc(int i,int j,int d){
	int x=i+j+N,y=i-j+N;
	return f[(x/d)&1][(y/d)&1];
}	
	
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) putchar(calc(i,j,d));
		puts("");
	}
	
	return 0;
}
			