#include <bits/stdc++.h>
using namespace std;
char s[2][2]={'R','Y','G','B'};
char so(int i,int j,int k){
	int a=i+j,b=i-j;
	a+=2027,b+=2027;
	a/=k,b/=k;
	a=a&1,b=b&1;
	return s[a][b];
}
int main(){
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) 
			printf("%c",so(i,j,k));
		printf("\n");
	}
}