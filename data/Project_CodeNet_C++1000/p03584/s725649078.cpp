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

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

ll n;
ll k;
ll a[100100],b[100100];
ll ans=0;
int main(){
	cin>>n>>k;
	REP(i,n)cin>>a[i]>>b[i];
	ll tans=0;
	for(int i=29;i>=0;i--){
		if(!(k>>i&1))continue;
		ll t1=((k>>(i+1))<<(i+1))+(1<<(i))-1;
		//printb(t1);
		//cout<<endl;
		//cout<<i<<endl;
		tans=0;
		for(int j=0;j<n;j++){
			if(t1>=a[j]&&((t1-a[j])==(t1^a[j]))){
				tans+=b[j];
			}
		}
		//cout<<tans<<endl;
		ans=max(ans,tans);
	}
	tans=0;
	for(int j=0;j<n;j++){
		if(k>=a[j]&&((k-a[j])==(k^a[j]))){
			tans+=b[j];
		}
	}
	//cout<<0<<" "<<tans<<endl;
	ans=max(ans,tans);	
	cout<<ans<<endl;
	return 0;
}