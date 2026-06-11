#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=m;++j){
			int a=(i+j+m)/d%2,b=(i-j+m)/d%2;
			char c="RGYB"[(a<<1)+b];
			printf("%c",c);
		}
		puts("");
	}
		
	return 0;
}