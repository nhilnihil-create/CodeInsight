#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
pair<int,int> t[MAXN*9];
int tot,n,h,w;
inline bool bound(int x,int y)
{
	return x>1 && x<h && y>1 && y<w;
}
int cnt[15];
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=-1;j<=1;++j)
			for(int k=-1;k<=1;++k)
				if(bound(a+j,b+k))t[++tot]=make_pair(a+j,b+k);
	}
	sort(t+1,t+tot+1);
	int p=1,sum=0;
	while(p<=tot){
		int now=1;
		while(t[p+1]==t[p])++p,++now;
		++cnt[now];
		++p;
		++sum;
	}
	cout<<(long long)(h-2)*(w-2)-sum<<endl;
	for(int i=1;i<=9;++i){
		cout<<cnt[i]<<endl;
	}
	return 0;
}
