#include <cstdio>

using namespace std;

const int N=510;

int n,x[N],a[N*N];
bool use[N];

void Init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&x[i]),a[x[i]]=i;
}

void Solve()
{
	bool fl=1;
	for (int i=1;i<=n*n && fl;++i)
		if (a[i] && !use[a[i]])
		{
			use[a[i]]=1;
			int cnt=a[i]-1;
			for (int j=1;j<i && cnt;++j)
				if (!a[j])
				{
					a[j]=a[i];
					cnt--;
				}
			if (cnt) fl=0;
		}
	for (int i=1;i<=n;++i) use[i]=0;
	for (int i=n*n;i>=1 && fl;--i)
		if (a[i] && !use[a[i]])
		{
			use[a[i]]=1;
			int cnt=n-a[i];
			for (int j=n*n;j>i && cnt;--j)
				if (!a[j])
				{
					a[j]=a[i];
					cnt--;
				}
			if (cnt) fl=0;
		}
	if (!fl) printf("No\n");
	else 
	{
		printf("Yes\n");
		for (int i=1;i<=n*n;++i)
			printf("%d%c",a[i],i==n*n?'\n':' ');
	}
}

int main()
{
	Init();
	Solve();
	return 0;
}