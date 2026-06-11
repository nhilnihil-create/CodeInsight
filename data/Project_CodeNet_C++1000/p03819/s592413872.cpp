#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=LLONG_MAX;
const int inf=INT_MAX;
const int nmax=3e5+5;
const int mod=1e9+7;
using namespace std;
int n,m,i,idx,j,bit[nmax],ans[nmax];
pair<int,int>a[nmax];
vector<int>d[nmax];
void upd(int i)
{
	for(;i<=m;i+=i&(-i))bit[i]++;
}
int qry(int i)
{
	int rs=0;
	for(;i>=1;i-=i&(-i))rs+=bit[i];
	return rs;
}
int main()
{
    //freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i].fr>>a[i].sc;
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)for(j=i;j<=m;j+=i)d[j].pb(i);
	for(i=1;i<=m;i++)
	{
		while(a[idx+1].fr<=i && idx<n)
		{
			idx++;
			upd(a[idx].sc);
		}
		for(j=0;j<d[i].size();j++)ans[d[i][j]]+=qry(min(m,i+d[i][j]-1))-qry(i-1);
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
}