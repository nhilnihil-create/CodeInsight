#include<bits/stdc++.h>
#define LL long long
#define db double

using namespace std;
const int N=400+10;
LL rd()
{
    LL x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
int p[N],hd,tl,nt;

int main()
{
	LL rs=rd()+1;
	hd=201,tl=200,nt=0;
	int w=50;
	while(!(rs>>w&1)) --w;
	for(int i=w-1;~i;--i)
	{
		++nt,p[++tl]=nt;
		if(rs>>i&1) ++nt,p[--hd]=nt;
	}
	printf("%d\n",(nt<<1));
	for(int i=1;i<=nt;++i) printf("%d ",i);
	for(int i=hd;i<=tl;++i) printf("%d ",p[i]);
	return 0;
}
