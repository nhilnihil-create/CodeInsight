#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define	inf (ll)1e15
#define mod 1000000007
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

using namespace __gnu_pbds;
using namespace std;

inline string str_inp(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string line_inp(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;


const int S=200100;
int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif
	int n,m;
	while(~sf("%d %d",&n,&m))
	{
		int a[m+5],b[m+5],c[m+5],dis[n+5][n+5];


		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)dis[i][j]=0;
				else dis[i][j]=100000000;
			}
		}

		for(int i=1;i<=m;i++)
		{
			sf("%d %d %d",&a[i],&b[i],&c[i]);
		}

		for(int i=1;i<=m;i++)
		{
			dis[a[i]][b[i]]=min(dis[a[i]][b[i]],c[i]);
			dis[b[i]][a[i]]=min(dis[b[i]][a[i]],c[i]);
		}

		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}

		int ans=m;
		for(int i=1;i<=m;i++)
		{
			bool has=false;
			for(int j=1;j<=n;j++)
			{
				if(dis[j][a[i]]+c[i]==dis[j][b[i]])has=true;
			}
			if(has)ans--;
		}
		pf("%d\n",ans);
	}
    return 0;
}
 
