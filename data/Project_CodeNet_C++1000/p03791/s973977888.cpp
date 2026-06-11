#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,itit )  for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define sz(s) (int)s.size()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

ll power(ll x,ll y){
	ll t=1;
	while(y>0){
		if(y%2) y-=1,t=t*x%mod;
		else y/=2,x=x*x%mod;
	}
return t;
}

ll x[N],val[N],n;
set <ll> s;

int main(){
	ll finder=0,ans=1;
	scanf("%lld",&n);
	REP(i,n){
		scanf("%lld",&x[i]);
		s.insert(x[i]);
	}
	REPP(i,1,2*n-2){
		if (s.find(i)!=s.end()){
			if (i%2==0&&finder==i/2)
				ans=(ans*(i/2+1))%mod;
			else finder++;
		}
	}
	REP(i,n) if (x[i]>(2*n-3)) finder++;
	REPP(i,2,finder+1) ans=(ans*i)%mod;
	printf("%lld\n",ans);
	return 0;
}