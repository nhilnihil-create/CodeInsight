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
#define	inf (int)1e5
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


const int S=45;
const int N=405;
int n,ma,mb;
int a[S+5],b[S+5],c[S+5];
int dp[N+5][N+5];

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif
	while(~sf("%d %d %d",&n,&ma,&mb))
	{
		for(int i=0;i<n;i++)sf("%d %d %d",&a[i],&b[i],&c[i]);

		for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j]=inf;
		dp[0][0]=0;
		for(int i=0;i<n;i++)
		{
			for(int ta=N;ta>=0;ta--)
			{
				for(int tb=N;tb>=0;tb--)
				{
					if(ta-a[i]>=0 && tb-b[i]>=0)dp[ta][tb]=min(dp[ta][tb],c[i]+dp[ta-a[i]][tb-b[i]]);
				}
			}
		}

		int ans=inf;
		for(int ta=1;ta<=N;ta++)
		{
			for(int tb=1;tb<=N;tb++)
			{
				if(ta*mb==tb*ma && dp[ta][tb]<ans)
				{
					ans=dp[ta][tb];
				}
			}
		}
		if(ans==inf)puts("-1");
		else pf("%d\n",ans);
	}
    return 0;
}
 
