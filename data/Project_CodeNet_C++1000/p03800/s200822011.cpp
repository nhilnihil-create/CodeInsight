#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int n;
char s[N];
int x[N];
int sp[N];
/*sheep: 0,wolf: 1
o: 0,x: 1*/

int main(){
	scanf("%d%s",&n,s);
	for(int i=1;i<=n;i++) x[i]=s[i-1]=='o'?0:1;
	for(int k=0;k<4;k++){
		sp[1]=k&1;
		sp[2]=k>>1&1;
		for(int i=3;i<=n;i++) sp[i]=sp[i-1]^x[i-1]^sp[i-2];
		if(sp[n]^x[n]^sp[n-1]!=sp[1]||sp[1]^x[1]^sp[n]!=sp[2]) continue;
		else {
			for(int i=1;i<=n;i++) printf("%c",sp[i]?'W':'S');
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}