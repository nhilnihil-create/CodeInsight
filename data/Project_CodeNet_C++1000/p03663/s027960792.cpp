#include<bits/stdc++.h>
using namespace std;
#define LL long long

int Ans=9999999;

bool check2(LL val)
{
	char A[50],B[50];
	sprintf(A,"%lld",val);
	sprintf(B,"%d",Ans);

	int i,n=min(strlen(A),strlen(B));
	bool flag;
	for (i=0;i<n;i++)
	{
		if (A[i]<B[i]) {flag=1; break;}
		if (A[i]>B[i]) {flag=0; break;}
	}
	if (i==n) flag=strlen(A)<=strlen(B);

	printf("? %lld : %c %d %d\n",val,flag^(val<=Ans)?'N':'Y',flag,val<=Ans);

	return !(flag^(val<=Ans));
}

bool check(LL val)
{
	char c;
	printf("? %lld\n",val); fflush(stdout);
	c=getchar();
	while (c!='Y'&&c!='N') c=getchar();
	return c=='Y';
}

bool ten(int val)
{
	if (val==1) return 1;
	return (val%10==0)&&ten(val/10);
}

bool pass(int val)
{
	if (val==1) return 1;
	if (val==1000000000) return 0;
	if (ten(val)) val--;
	return check(val)^check(val*1000000000ll-1ll);
}

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	if (check(1000000000000000ll))
	{
		LL val=1,checknum=5;
		while (val<=1000000000ll)
		{
			if (check(checknum)) {printf("! %lld\n",val); return 0;}
			val*=10;
			checknum*=10;
			checknum+=5;
		}
	}

	int i,v1=1,v2=9,L,R,mid;

	for (i=1;i<=9;i++)
	{
		if (check(v1)&&check(v2)) L=v1,R=v2;
		v1=v1*10;
		v2=v2*10+9;
	}

	while (L<=R)
	{
		mid=(L+R)>>1;
		if (check(mid*1000ll))
			R=mid-1;
		else
			L=mid+1;
	}
	printf("! %d\n",L);
}
