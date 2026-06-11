#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(ll i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
typedef tuple<ll,ll,ll> Tu;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
ll n,m;
ll x[100100];
ll r1[100100];
ll rep[100100];
int main(){
	cin>>n>>m;
	REP(i,n)cin>>x[i];
	sort(x,x+n);
	ll co=1;
	r1[x[0]%m]++;
	FOR(i,1,n){
		r1[x[i]%m]++;
		if(x[i-1]==x[i]){
			co++;
			if(i==n-1){
				rep[x[n-1]%m]+=(co/2);
			}
		}else{
			rep[x[i-1]%m]+=(co/2);
			co=1;
		}
	}
	ll ans=0;
	ans+=(r1[0]/2);
	//cout<<0<<" "<<ans<<endl;
	for(ll i=1;i<=m/2;i++){
		if(i==m-i){
			ans+=(r1[i]/2);
		}else if(r1[i]>r1[m-i]){
			ans+=r1[m-i];
			ll t1=r1[i]-r1[m-i];
			rep[i]*=2;
			if(r1[m-i]>r1[i]-rep[i]){
				ans+=(t1)/2;
			}else{
				ans+=(rep[i])/2;
			}
		}else{
			ans+=r1[i];
			ll t1=r1[m-i]-r1[i];
			rep[m-i]*=2;
			if(r1[i]>r1[m-i]-rep[m-i]){
				ans+=(t1)/2;
			}else{
				ans+=(rep[m-i])/2;
			}
		}
		//cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}