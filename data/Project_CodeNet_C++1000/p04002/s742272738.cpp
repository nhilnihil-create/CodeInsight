#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=100010;
int H,W,N,x[maxn],y[maxn];
map<pair<int,int>,bool>black;
long long ans[10];
int count(int a,int b){
	int ret=0;
	for(int i=a;i<=a+2;i++)
		for(int j=b;j<=b+2;j++)
			if(black[make_pair(i,j)])
				ret++;
	return ret;
}
int main(){
	//freopen("in","r",stdin);
	H=read(),W=read();
	N=read();
	for(int i=1;i<=N;i++){
		x[i]=read(),y[i]=read();
		black[make_pair(x[i],y[i])]=1;
	}
	for(int i=1;i<=N;i++)
		for(int j=x[i]-2;j<=x[i];j++)
			for(int k=y[i]-2;k<=y[i];k++)
				if(j>=1&&k>=1&&j+2<=H&&k+2<=W)
					ans[count(j,k)]++;
	for(int i=1;i<=9;i++)
		ans[i]/=i;
	ans[0]=1LL*(H-2)*(W-2);
	for(int i=1;i<=9;i++)
		ans[0]-=ans[i];
	for(int i=0;i<=9;i++)
		printf("%lld\n",ans[i]);
	return 0;
}

