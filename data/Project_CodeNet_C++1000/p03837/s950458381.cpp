#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <math.h>
//#include <bits/stdc++.h>
#define ll long long
#define wtcl return
using namespace std;

inline int read()
{
	ll s = 0, f = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 3ll) + (s << 1ll) + (ch ^ 48ll));
	return s * f ;
}
inline void out(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

const int maxn = 1005;
const int inf = 999999999;

int look[maxn][maxn];
int n,m;
int dis[maxn][maxn];
int path[maxn][maxn];
void init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			if(i==j) dis[i][j]=0;
			else
			dis[i][j]=inf;
		}

}
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			path[i][j]= j;
	}
    for(int k=1;k<=n;k++)
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[i][k]+dis[k][j]<dis[i][j])
    			{
    				dis[i][j]=dis[i][k]+dis[k][j];
          			//dis[j][i]=dis[i][k]+dis[k][j];
          			path[i][j] = path[i][k];
//          			cout<<i<<" "<<j<<" "<<k<<endl;
//          			system("pause");
				}
			}
		}
	}
}
void finde(int u, int v)
{
	while(u!=v)
	{
		//cout << u << "->";
		look[u][path[u][v]]=1;
        u = path[u][v]; 
    }
    //cout << u<<endl;;
    //look[u][v]=1; 
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		memset(look,-1,sizeof(look));
		init();
		for(int i=0;i<m;i++)
		{
			int u,v,val;
			u = read();
			v = read();
			val = read();
			dis[u][v]=val;
			dis[v][u]=val;
			look[u][v] = 0;
		}
		floyd();
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				//printf("从 %d 到 %d 的长度是 %d 路径是：",i,j,dis[i][j]);
				finde(i,j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//printf("%d ",look[i][j]);
				if(look[i][j] == 0)
				{
					ans++;
					//cout<<"+";
				}
			}
			//puts("");
		}
		cout<<ans<<endl;
	}
	wtcl 0;
}

/**
3 3
1 2 1
1 3 1
2 3 3

3 2
1 2 1
2 3 1

3 3
1 2 10
1 3 5
2 3 5

6 7
1 2 1
2 4 1
4 5 2
4 6 3
6 5 1
5 3 1
3 1 1
*/
