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

ll n,x;
ll a[2010];
int main(){
	cin>>n>>x;
	REP(i,n){
		cin>>a[i];
	}
	ll ans=INFl;
	REP(i,n){
		ll tans=x*i;
		multiset<ll> m1;
		m1.clear();
		for(int j=n-i-1;j<n;j++){
			m1.insert(a[j]);
		}
		for(int k=0;k<n;k++){
			auto itr=m1.find(a[(k-i-1+n)%n]);
			m1.erase(itr);
			m1.insert(a[k]);
			tans+=*m1.begin();
		}
		ans=min(tans,ans);
	}
	cout<<ans<<endl;
	return 0;
}