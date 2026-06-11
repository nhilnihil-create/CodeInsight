#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn=500+7;
int n,m,H,W;
int main(){
	std::cin>>n>>m>>H>>W;
	bool h=(n%H>0),w=(m%W>0);
	if(!h && !w)return puts("No"),0;
	puts("Yes");
	if(h){
		int k=(n+H-1)/H,x=n*maxn+1,y=k*maxn;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				printf("%d%c",i%H==1 ? x-y : -y," \n"[j==m]);
	}else {
		int k=(m+W-1)/W,x=m*maxn+1,y=k*maxn;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				printf("%d%c",j%W==1 ? x-y : -y," \n"[j==m]);
	}return 0;
}
