#include<bits/stdc++.h>
using namespace std;

int read()
{
	int ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=0;
	if(ch=='-')flag=1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10+ch-'0';
	if(flag)ans=-ans;
	return ans;
}

long long rell()
{
	long long ans=0;
	char ch=getchar();
	for(;(ch<'0' || ch>'9') && ch!='-';ch=getchar());
	bool flag=0;
	if(ch=='-')flag=1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())ans=ans*10ll+(long long)(ch-'0');
	if(flag)ans=-ans;
	return ans;
}

void writ(int n)
{
	char ch[25];
	int m=0;
	if(n<0)putchar('-'),n=-n;
	if(n==0)
	{
		putchar('0');
		return;
	}
	for(;n;)ch[m++]=n%10ll+'0';
	for(;m;)putchar(ch[--m]);
}

void wrll(long long n)
{
	char ch[25];
	int m=0;
	if(n<0)putchar('-'),n=-n;
	//cout<<n<<endl;
	if(n==0)
	{
		putchar('0');
		return;
	}
	for(;n;n/=10ll)ch[m++]=n%10ll+'0';
	for(;m;)putchar(ch[--m]);
}

int main()
{
	long long m=rell(),k=51,n=50;
	long long rm=m-m/k*n;
	wrll(n);puts("");
	//cout<<rm<<endl;
	for(int i=0;i<50;i++)
	{
		long long o=n-m%k-1ll+rm/(n-(long long)i)*k;
		//cout<<o<<endl;
		wrll(o);putchar(' ');
		rm-=rm/(n-(long long)i);
	}
	puts("");
	return 0;
}
