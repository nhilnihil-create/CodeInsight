#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define X first
#define Y second
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;

const int INF=1<<30;
const int Mod=1000000000+7;

int n;
int a[N];

int gcd(int x,int y)
{
	int tmp;
	while (y)
	{
		tmp=x%y;
		x=y,y=tmp;
	}
	return x;
}

bool Solve()
{
	if (n==1) return a[1]!=1;
	
	bool flag=true;
	for (int i=1;i<=n;i++) if (a[i]!=1) flag=false;
	if (flag) return 0;
	
	int cnt=0;
	for (int i=1;i<=n;i++) if (!(a[i]&1)) cnt++;
	if (cnt&1) return 1;
	else 
	{
		if (n-cnt>=2) return 0;
		bool flag=false;
		for (int i=1;i<=n;i++) if (a[i]>1 && (a[i]&1))
		{
			flag=true;
			a[i]--;
			int d=a[1];
			for (int j=2;j<=n;j++) d=gcd(d,a[j]);
			for (int j=1;j<=n;j++) a[j]/=d;
			return !Solve();
		}
		if (!flag) return 0;
	}
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d",&n); 
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (Solve()) printf("First\n");
	else printf("Second\n");
	
	return 0;
}