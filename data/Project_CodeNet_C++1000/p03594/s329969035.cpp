#include<bits/stdc++.h>
using namespace std;
int m,n,k;
char cl[2][2]={{'R','B'},{'G','Y'}};

inline int in(){
	int X=0,W=1;
	char ch=0;
	while(!isdigit(ch)){
		if(ch=='-') W=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		X=(X<<1)+(X<<3)+(ch^'0');
		ch=getchar();
	}
	return X;
}

char co(int x,int y){
	int u=x+y+2000,v=x-y+2000;
	u/=k,v/=k;
	u&=1,v&=1;
	return cl[u][v];
}

int main(){
	m=in(),n=in(),k=in();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			printf("%c",co(i,j));
		puts("");
	}
}