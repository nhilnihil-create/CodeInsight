#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

inline char gc()
{
		static const int L = 1000;
		static char sxd[L], *sss = sxd, *ttt = sxd;
		if(sss == ttt)
		{
				ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
				if(sss == ttt)
						return EOF;
		}
		return *sss++;
}

#define dd c = getchar()
inline int read(int& x)
{
		x = 0;
		char dd;
		bool f = false;
		for(; !isdigit(c); dd)
		{
				if(c == EOF)
						return -1;
				if(c == '-')
						f = true;
		}
		for(; isdigit(c); dd)
				x = (x << 1) + (x << 3) + (c ^ 48);
		if(f)
				x = -x;
		return 1;
}
#undef dd

int i,j,n,x[100010],m,d[100010],z[100010],t[100010],c;
long long K;
double a[100010];
int main()
{
	read(n);
	for(i=1;i<=n;++i) read(x[i]);
	read(m);
	cin>>K;
	for(i=1;i<=n;i++)
	{
		d[i]=i;
		z[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		read(c);
		swap(d[c],d[c+1]);
	}
	while(K)
	{
		if(K&1)
		{
			for(i=1;i<=n;i++) t[i]=z[d[i]];
			for(i=1;i<=n;i++) z[i]=t[i];
		}
		for(i=1;i<=n;i++) t[i]=d[d[i]];
		for(i=1;i<=n;i++) d[i]=t[i];
		K>>=1;
	}
	for(i=1;i<=n;i++)
	  a[i]=x[z[i]]-x[z[i]-1];
	for(i=1;i<=n;i++)
	  printf("%.1lf\n",a[i]+=a[i-1]);
	return 0;
}