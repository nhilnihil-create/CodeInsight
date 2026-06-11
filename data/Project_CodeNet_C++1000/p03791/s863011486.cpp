#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

#define mod 1000000007

int n;
ll a[111111];
ll fac[111111];

ll dfs(int s,int rem){
	int l=s;
	while(l<n&&2*(l-rem)+1<=a[l])l++; // [s,l]=removable
	//dbg(l);
	if(l==n)return fac[n-rem]%mod;
	else return (l+1-rem)*(dfs(l+1,rem+1)%mod)%mod;
}

int main(){
	cin.sync_with_stdio(false);
	fac[0]=fac[1]=1;
	repl(i,1,111111)fac[i+1]=fac[i]*(i+1)%mod;
	cin>>n;
	rep(i,n)cin>>a[i];
	cout<<dfs(0,0)%mod<<endl;
	return 0;
}
