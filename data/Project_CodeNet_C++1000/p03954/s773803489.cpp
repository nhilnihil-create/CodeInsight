#include<cstdio>
#include<algorithm>
int t,n;
int __a[333333],*a=__a+155555,__b[333333],*b=__b+155555,*exc;
inline int top()
{
	register int i,ii;
	if(b[0]==b[1]||b[0]==b[-1])return b[0];
	for(i=1,ii=-1;i<t;i++,ii--)
	{
		if(b[i+1]==b[i])goto T;
		if(b[ii-1]==b[ii])goto S;
	}return(t&1)^b[0];
	T:return b[i];
	S:return b[ii];
}
inline int valid(int mid)
{
	register int i;
	for(i=-t;i<=t;i++)
		b[i]=(a[i]>=mid);
	return top();
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	t=n-1;
	for(i=-t;i<=t;i++)
		scanf("%d",&a[i]);
	int l=1,r=2e9;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(valid(mid))l=mid;
		else r=mid;
	}printf("%d\n",l);
}