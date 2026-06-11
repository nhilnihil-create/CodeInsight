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
int n,ma,mb;
int a[S+5],b[S+5],c[S+5];
int dp[S+5][400+5][400+5];

bool Check(int ta,int tb)
{
	if(!ta && !tb)return false;
	int g=__gcd(ta,tb);
	if(ta/g==ma && tb/g==mb)return true;
	return false;
}

int Solve(int pos,int ta,int tb)
{
	if(pos==n)
	{
		if(Check(ta,tb))return 0;
		return inf;
	}
	if(Check(ta,tb))return 0;
	if(dp[pos][ta][tb]!=-1)return dp[pos][ta][tb];

	int mn=min(c[pos]+Solve(pos+1,ta+a[pos],tb+b[pos]),Solve(pos+1,ta,tb));
	return dp[pos][ta][tb]=mn;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif
	while(~sf("%d %d %d",&n,&ma,&mb))
	{
		for(int i=0;i<n;i++)sf("%d %d %d",&a[i],&b[i],&c[i]);

		mem(dp,-1);
		int cost=Solve(0,0,0);
		if(cost>=inf)puts("-1");
		else pf("%d\n",cost);
	}
    return 0;
}
 
