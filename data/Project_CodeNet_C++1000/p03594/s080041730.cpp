#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=510;
const char col[4]={'R','Y','G','B'};
int n,m,d;
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;puts(""),++i)
		for (int j=1;j<=m;++j){
			int x=(i+j)/d,y=(i-j+m)/d;
			putchar(col[  ((x&1)*2)|(y&1)  ]);
		}
	return 0;
}