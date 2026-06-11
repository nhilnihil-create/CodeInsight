#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
#define REP(i,st,ed) for(int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(int i=st,i##end=ed;i>=i##end;--i)
const char str[]="GBYR";
const int maxn=505;
int n,m,d;
char ans[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	REP(i,1,n)
		REP(j,1,m)
			ans[i][j]=str[((((i+j)/d)&1)<<1)|(((i-j+m)/d)&1)];
	REP(i,1,n)
		puts(ans[i]+1);
	return 0;
}