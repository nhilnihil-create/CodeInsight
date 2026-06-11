#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,D;
char ch[5]="RYGB";
const int inf=1e9;
int main(){
	scanf("%d%d%d",&n,&m,&D);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int flag1=(i+j+inf)%(D*2);
			int flag2=(i-j+inf)%(D*2);
			int s1=(flag1/D)&1;
			int s2=(flag2/D)&1;
			putchar(ch[s1*2+s2]);
		}
		putchar('\n');
	}
	return 0;
}