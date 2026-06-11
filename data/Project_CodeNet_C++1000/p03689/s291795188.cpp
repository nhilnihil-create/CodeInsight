#include<iostream>
#include<cstdio>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool B[MN+5][MN+5];
int n,m,a,b,num1,num2;
int main()
{
	n=read();m=read();a=read();b=read();num1=n*m;
	for(int i=a;i<=n;i+=a)
		for(int j=b;j<=m;j+=b)
			B[i][j]=1,--num1,++num2;
	//ax+b(-(a*b-1)*x-1)
	
	if(num1-num2*(a*b-1)<=0)  return 0*puts("No");
	else puts("Yes");
	int l=1,r=1e9,mid,res=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(-1LL*(a*b-1)*mid-1<-1e9) r=mid-1;
		else if(1LL*num1*mid+1LL*num2*(-(a*b-1)*mid-1)<=0) l=mid+1;
		else res=mid,r=mid-1;
	}
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j) printf("%d ",B[i][j]?-res*(a*b-1)-1:res);
	return 0;
}

