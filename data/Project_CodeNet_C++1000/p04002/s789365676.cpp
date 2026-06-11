#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=1e5+10;
P sqr[MAXN*10];
ll sum=0,cnt[15];
int n,m,k,x,y,tot;
int dx[]={-2,-2,-2,-1,-1,-1,0,0,0};
int dy[]={-2,-1,0,-2,-1,0,-2,-1,0};

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=0;j<9;j++)
		{
			int fx=x+dx[j],fy=y+dy[j];
			if(fx>0&&fy>0&&fx<=n-2&&fy<=m-2)
				sqr[++tot]=P(fx,fy);
		}
	}
	
	sort(sqr+1,sqr+tot+1);
	int cur=1;
	for(int i=2;i<=tot;i++)
		if(sqr[i]==sqr[i-1]) cur++;
		else cnt[cur]++,cur=1;
	if(k) cnt[cur]++;//²»ÒªÍü¼Ç¶ÔÄ©Î²µÄ´¦Àí 
	
	for(int i=1;i<=9;i++) sum+=cnt[i];
	cnt[0]=1ll*(m-2)*(n-2)-sum;
	for(int i=0;i<10;i++) printf("%lld\n",cnt[i]);
	return 0;
}