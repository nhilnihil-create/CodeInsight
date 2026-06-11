#include <bits/stdc++.h> 
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// #define ll long long 
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=1e5+2;
int d[101][101];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	vector<pair<int,pii>> v;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i==j) d[i][j]=0; else d[i][j]=1e12;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		d[x][y]=min(d[x][y],z);
		d[y][x]=min(d[y][x],z);
		v.pb({z,{x,y}});
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int ans=m;
	for(int i=0;i<m;i++)
	{
		bool ok=false;
		for(int j=1;j<=n;j++)
		{
			if(d[j][v[i].se.fi]+v[i].fi==d[j][v[i].se.se]){
				ok=true;
				break;
			}
		}
		if(ok) ans--;
	}
	cout<<ans;
}
// I never lose. I either win or I learn