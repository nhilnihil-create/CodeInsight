/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef long long ll;
template<class T>void chkmin(T &a,T b){a=a<b?a:b;}
template<class T>void chkmax(T &a,T b){a=a>b?a:b;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int a[1024][1024];
int n,m,d;
int chk(int x,int y){
	for(int i=0;i<=d;++i){
		if(x-i>=1&&y-d+i>=1&&a[x-i][y-d+i]==a[x][y])return 0;
		if(x-i>=1&&y+d-i<=m&&a[x-i][y+d-i]==a[x][y])return 0;
		if(x+i<=n&&y-d+i>=1&&a[x+i][y-d+i]==a[x][y])return 0;
		if(x+i<=n&&y+d-i<=m&&a[x+i][y+d-i]==a[x][y])return 0;
	}
	return 1;
}
void out(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d",a[i][j]);
		}
		putchar('\n');
	}
	exit(0);
}
void dfs(int x,int y){
	for(a[x][y]=0;a[x][y]<4;++a[x][y]){
		if(chk(x,y)){
			if(y-m)dfs(x,y+1);
			else if(x-n)dfs(x+1,1);
			else out();
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int t=0;
			if(((i+j)/d)&1)++t;
			if((((n+1-i+j)/d)&1))t+=2;
			switch(t){
				case 0:putchar('R');break;
				case 1:putchar('Y');break;
				case 2:putchar('G');break;
				case 3:putchar('B');break;
			}
		}
		putchar('\n');
	}
	return 0;
}

