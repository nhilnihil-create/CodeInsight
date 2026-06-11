#include<iostream>
#include<cstdio>
#include<cstring>
const int N=100010;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,m;
int a[N];
bool spj()
{
	if(m!=n-1)return 0;
	for(int i=1;i<=n;i++)if(a[i]&1){if(a[i]==1)return 0;a[i]--;}
	int d=a[1];
	for(int i=2;i<=n;i++)d=gcd(d,a[i]);
	for(int i=1;i<=n;i++)a[i]/=d;
	return 1;
}
bool check()
{
	m=0;
	for(int i=1;i<=n;i++)m+=(a[i]&1)==0;
	if(m&1)return 1;
	if(!spj())return 0;
	return !check();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	printf("%s\n",check()?"First":"Second");
	return 0;
}
