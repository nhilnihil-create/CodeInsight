#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
map<ll,int>mp,g;
ll f[N];
ll C[N][N];
void solve(int n){
	for(int i=1;i<=n;i++) C[i][0]=C[i][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];	
}
int main(){
	ll n;int a,b;
	solve(50);
	cin>>n>>a>>b;
	map<ll,int>::reverse_iterator it;
	for(int i=1;i<=n;i++){
		cin>>f[i],mp[f[i]]++;
	}
	sort(f+1,f+n+1,greater<ll>());
	ll cnt=0,x=0;
	for(int i=1;i<=a;i++){
	   x+=f[i];
	   if(f[i]==f[a]) cnt++;
	}
	printf("%.6f\n",(double)x/a);
	ll c=0;
	x=f[a];
	if(cnt<a) c=C[mp[x]][cnt];
	else {
		for(int i=a;i<=b&&mp[x]>=i;i++){
			c+=C[mp[x]][i];
		}
	}
	cout<<c<<endl;
	return 0;
}