#include<bits/stdc++.h>
using namespace std;
 
char ch[2][2]={{'R','B'},{'G','Y'}}; int n,m,k;
char calc(int x,int y){
	int a=x+y,b=x-y;
	a+=2000; b+=2000;
	a/=k; b/=k; a&=1; b&=1;
	return ch[a][b];
}
int main(){
	scanf("%d%d%d",&m,&n,&k);
	int i,j;
	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++) printf("%c",calc(i,j)); puts("");
	}
	return 0;
}