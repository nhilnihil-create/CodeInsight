#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;
typedef unsigned int u32;
#define pb push_back

int o[100];char str[5];
void Print(LL num,int tag=1)
{
	int l=0;printf("? ");
	while (num) o[++l]=num%10,num/=10;
	for (int i=l;i>=1;i--) printf("%d",o[i]);
	if (tag) for (int i=l+1;i<=18;i++) printf("0");
	puts("");fflush(stdout);
}
void Printo(int l)
{
	printf("? ");
	for (int i=1;i<=l;i++) printf("%d",o[i]);
	puts("");fflush(stdout);
}
int x[100],y[100];
bool comp(LL a,LL b)
{
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	int l1=0;while (a) x[++l1]=a%10,a/=10;
	int l2=0;while (b) y[++l2]=b%10,b/=10;
	for (int i=1,j=l1;i<j;i++,j--) swap(x[i],x[j]);
	for (int i=1,j=l2;i<j;i++,j--) swap(y[i],y[j]);
	x[l1+1]=-1;y[l2+1]=-1;
	for (int i=1;;i++)
		if (x[i]!=y[i]) return x[i]<y[i];
}
int main()
{
	
	LL lb=1e8-1,rb=1e9;
	while (rb-lb>1) {
		LL mid=lb+rb>>1;
		Print(mid);scanf("%s",str);
		(*str=='Y')?rb=mid:lb=mid;
	}
	
	while (rb%10==0) rb/=10;
	int l=0;memset(o,0,sizeof o);LL num=rb;
	
	num=rb+1;Print(num,0);scanf("%s",str);
	if ((*str=='Y')==comp(rb,rb+1)) {
		printf("! %lld\n",rb);
		fflush(stdout);return 0;
	}
	num=rb;
	while (num) o[++l]=num%10,num/=10;
	for (int i=1,j=l;i<j;i++,j--) swap(o[i],o[j]);
	num=rb;
	for (int i=l+1;;i++)
	{
		o[i]=1;num*=10;Printo(i);
		scanf("%s",str);
		if (*str=='Y') {
			printf("! %lld\n",num);
			fflush(stdout);return 0;
		}
		o[i]=0;
	}
	return 0;
}