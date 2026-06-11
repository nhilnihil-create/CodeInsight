#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define X first
#define Y second
#define N 200010
#define M 3000010
typedef long long ll;
typedef pair<int,int> pii;

const int Mod=1000000007;
const ll INF=1ll<<60;


int n,t,ans=1;
int lis[N];

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);

	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		if (x<2*t+1) ans=1ll*ans*(t+1)%Mod;
		else lis[++t]=x;
	}
	while (t) ans=1ll*ans*t%Mod,t--;
	printf("%d\n",ans);

    return 0;
}