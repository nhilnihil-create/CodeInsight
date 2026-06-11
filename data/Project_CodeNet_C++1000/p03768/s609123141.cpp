/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,m,q,appe[100010][20],coap[100010],len=0;//appe:appearance
int list_top[100010],val[200010],nxt[200010];

void add(int x,int y)
{
	val[++len]=y;
	nxt[len]=list_top[x];
	list_top[x]=len;
}

int main()
{
	cin>>n>>m;
	rep(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	cin>>q;
	repn(i,q)
	{
		int x,y;
		scanf("%d%d%d",&x,&y,&coap[i]);
		appe[x][y]=i;
	}
	for(int i=9;i>=0;i--)//算能不能覆盖appe[j][i]之前要先算出appe[p][i+1]会不会被覆盖，所以i要倒着循环 
	{
		repn(p,n)
		{
			for(int k=list_top[p];k!=0;k=nxt[k])//i在这里代表可以控制的范围
			{
				int j=val[k];
				appe[j][i]=max(appe[j][i],appe[p][i+1]);/*远一条边距离就要加1，这里是看后者可不可以覆盖前者，
				可以说是一种dp，一个类似递归的过程，如果再之前的点把后者覆盖了，也会在前者上体现出来*/
			}	
		}	
	} 
	repn(i,n)
	{
		int lst=0;
		rep(j,11) lst=max(lst,appe[i][j]);
		cout<<coap[lst]<<endl;
	}
	rt0;
}