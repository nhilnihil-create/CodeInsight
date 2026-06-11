#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N=105;
int hx[N<<1];
 
inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}
 
int main(){
#ifndef ONLINE_JUDGE
//	freopen("a.in","r",stdin);
#endif
	int n=nxi(),ans=0;
	for(int i=1;i<=n<<1;++i){
		hx[i]=nxi();
	}
	std::sort(hx+1,hx+(n<<1)+1);
	for(int i=1;i<n<<1;i+=2){
		ans+=hx[i];
	}
	printf("%d\n",ans);
	return 0;
}