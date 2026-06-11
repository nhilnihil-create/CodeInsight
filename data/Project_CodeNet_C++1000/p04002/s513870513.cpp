#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;
	static int p;p=1;
	static char c;c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-'0');c=getchar();}
	x*=p;
}
int h,w,n;
typedef pair<int,int> pi;
map<pi,int>mp;
long long ans[10];
int main()
{
//	freopen("ARC061D.in","r",stdin);
//	freopen("ARC061D.out","w",stdout);
	read(h);read(w);
	read(n);
	for(int i=1;i<=n;i++)
	{
		static int a,b;
		read(a);read(b);
		for(int j=max(1,a-2);j<=min(a,h-2);j++)
			for(int k=max(1,b-2);k<=min(b,w-2);k++)
				mp[pi(j,k)]++;
	}
	long long sum=0;
	for(auto it:mp)ans[it.second]++;
	for(int i=1;i<=9;i++)sum+=ans[i];
	ans[0]=(long long)(h-2ll)*(w-2ll)-sum;
	for(int i=0;i<=9;i++)
		cout<<ans[i]<<endl;
	return 0;
}