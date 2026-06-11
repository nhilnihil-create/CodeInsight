// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char str[]="RGBY";
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a=((m+i+j)/k)%2,b=((m+i-j)/k)%2;
			printf("%c",str[a*2+b]);
		}
		putchar('\n');
	}
	return 0;
}
