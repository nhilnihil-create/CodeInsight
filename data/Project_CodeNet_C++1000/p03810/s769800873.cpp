#include<cstdio>
using namespace std;
const int maxn=100005;
int n,A[maxn],oc,ec,op;bool one;
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
inline int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		A[i]=read();
		(A[i]&1)?oc++:ec++;
		if(A[i]&1) op=i;
		if(A[i]==1) one=true;
	}
	if(one){printf("%s\n",(ec&1)?"First":"Second");return 0;}
	if(ec&1){printf("First\n");return 0;}
	if(n-ec>1&&!(ec&1)){printf("Second\n");return 0;}
	bool f=1;
	while(true)
	{
		A[op]--;
		int d=A[1];
		for(int i=2;i<=n;i++) d=gcd(d,A[i]);
		oc=ec=0;
		for(int i=1;i<=n;i++)
		{
			A[i]/=d;
			(A[i]&1)?oc++:ec++;
			if(A[i]&1) op=i;
			if(A[i]==1) one=true;
		}
		if(one){printf("%s\n",((ec&1)^f)?"First":"Second");return 0;}
		if(ec&1){printf("%s\n",f?"Second":"First");return 0;}
		if(n-ec>1&&!(ec&1)){printf("%s\n",f?"First":"Second");return 0;}
		f=!f;
	}
	return 0;
}