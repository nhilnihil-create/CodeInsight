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
	for(;n;n/=10)ch[m++]=n%10ll+'0';
	for(;m;)putchar(ch[--m]);
}

void wrll(long long n)
{
	char ch[25];
	int m=0;
	if(n<0)putchar('-'),n=-n;
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
	long long t=1,w=1e9;
	for(;t<=w;)
	{
		long long mid=(t+w)>>1;
		cout<<"? "<<mid<<"000000000"<<endl;
		char ch[233];
		scanf("%s",ch);
		if(ch[0]=='N')t=mid+1;else w=mid-1;
	}
	//cout<<w<<endl;
	for(;t%10ll==0ll;t/=10ll);
	bool flag=(t==1ll);
	for(;;)
	{
		t*=10ll;
		cout<<"? "<<t-1ll<<endl;
		char ch[233];
		scanf("%s",ch);
		if((ch[0]=='N')^flag)break;
	}
	cout<<"! "<<t/10ll<<endl;
	return 0;
}
