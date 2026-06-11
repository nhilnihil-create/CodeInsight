#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)) f=ch=='-'?-1:f,ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int N=100005;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

int a[N];
int n;
bool ok,res;

int main()
{
	//freopen("decrementing.in","r",stdin),freopen("decrementing.out","w",stdout);
	n=read(),ok=0;
	for (int i=1;i<=n;++i) a[i]=read();
	for (bool cur=0;!ok;cur^=1)
	{
		bool par=0,one=0;
		int even=0,odd=0;
		for (int i=1;i<=n;++i) par^=(a[i]-1)&1,one|=a[i]==1,odd+=a[i]&1;
		even=n-odd,ok=1;
		if (one) res=par^cur;
		else if (even&1) res=!cur;
		else if (odd>=2) res=cur;
		else
		{
			for (int i=1;i<=n;++i) if (a[i]&1) --a[i];
			int g=a[1];
			for (int i=2;i<=n;++i) g=gcd(g,a[i]);
			for (int i=1;i<=n;++i) a[i]/=g;
			ok=0;
		}
	}
	printf("%s\n",res?"First":"Second");
	//fclose(stdin),fclose(stdout);
	return 0;
}