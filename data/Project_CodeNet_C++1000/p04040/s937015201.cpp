#include<bits/stdc++.h>
using namespace std;
int h,w,a,b;
long long totalsum = 0,n,m,nm,facn,facm,facnm;
long long x,y,xy,facx,facy,facxy;
long long arr[100010],arr2[100010];

long long invmod(long long ac)
{
	int i,j;
	long long num[40],ans=1;
	int idx=1000000005;
//	int idx = 2;
	int idx3=30,idx2=1073741824;
	num[0] = ac;
	num[1] = ac*ac;
	num[1] %= 1000000007;
	for(i=2;i<=30;i++)
	{
		num[i] = num[i-1] * num[i-1];
//		printf("num[%d]=%lld\n",i,num[i]);
		num[i] %= 1000000007;
	}
//	while(idx>0)
//	{
//		if(idx >= idx2)
//		{
//			idx -= idx2;
//			ans *= num[idx3];
//			ans %= 1000000007;
//		}
//		idx3--;
//		idx2 /= 2;
//	}
	for(i=0;i<=30;i++)
	{
		j = (1 << i);
		if(idx & j )
		{
			ans *= num[i];
			ans %= 1000000007;
		}
	}
	return ans;
}

int main()
{
	int i,j,k;
//	for(i=1;i<10;i++)
//	printf("%lld\n",invmod(i));
	scanf("%d %d %d %d",&h,&w,&a,&b);
	
	n = 1-1;		facn=1;
	m = b-1;		facm=1;
	nm = n+m;		facnm=1;
	for(i=1;i<=n;i++)
	{
		facn *= i;
		facn %= 1000000007;
	}
	for(i=1;i<=m;i++)
	{
		facm *= i;
		facm %= 1000000007;
	}
	for(i=1;i<=nm;i++)
	{
		facnm *= i;
		facnm %= 1000000007;
	}
	
	x = a+1-1;	facx=1;
	y = w-b-1;	facy=1;
	xy = x+y;	facxy=1;
	for(i=1;i<=x;i++)
	{
		facx *= i;
		facx %= 1000000007;
	}
	for(i=1;i<=y;i++)
	{
		facy *= i;
		facy %= 1000000007;
	}
	for(i=1;i<=xy;i++)
	{
		facxy *= i;
		facxy %= 1000000007;
	}
	
	long long a1,a2,a3,a4,a5;
	for(i=1;i<=h-a;i++)
	{
		a1 = facn * facm;
		a1 %= 1000000007;
	//	a2 = facnm / a1;
//		printf("a1 = %lld * %lld = %lld\n",facn,facm,a1);
//		a2 = facnm * invmod(a1);
//		printf("a2 = facnm(%lld) * invmod(%lld)%d = %lld\n",facnm,a1,invmod(a1),a2);
		a2 = facnm * invmod(facn);
		a2 %= 1000000007;
		a2 *= invmod(facm);
		a2 %= 1000000007;
	//	printf("a2 = facnm(%lld) * invmod(%lld)%lld * invmod(%lld)%lld = %lld\n",facnm,facn,invmod(facn),facm,invmod(facm),a2);
		
		a3 = facx * facy;
		a3 %= 1000000007;
	//	a4 = facxy / a3;
	//	a4 = facxy * invmod(a3);
	//	printf("a4 = facxy(%lld) * invmod(%lld)%lld = %lld\n",facxy,a3,invmod(a3),a4);
		a4 = facxy * invmod(facx);
		a4 %= 1000000007;
		a4 *= invmod(facy);
		a4 %= 1000000007;
//		printf("x=%d y=%d\n",x,y);
//		printf("a4 = facxy(%lld) * invmod(%lld)%lld * invmod(%lld)%lld = %lld\n",facxy,facx,invmod(facx),facy,invmod(facy),a4);
		
		n++;
		facn *= n;
		facn %= 1000000007;	
		nm++;
		facnm *= nm;
		facnm %= 1000000007;
		
		x++;
		facx *= x;
		facx %= 1000000007;	
		xy++;
		facxy *= xy;
		facxy %= 1000000007;
		
		arr[i] = a2;
		arr2[h-a+1-i] = a4;
//		printf("arr[%d] , arr[%d]\n",i,h-a+1-i);
	//	totalsum += a2 * a4;
	//	totalsum %= 1000000007;
	}
	for(i=1;i<=h-a;i++)
	{
//		printf("i=%d\n",i);
		totalsum += arr[i] * arr2[i];
		totalsum %= 1000000007;
	}
	printf("%lld\n",totalsum);
}