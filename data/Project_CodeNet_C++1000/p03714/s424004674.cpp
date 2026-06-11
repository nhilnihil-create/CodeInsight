#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
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
int mdx[4]={0,1,0,-1},mdy[4]={-1,0,1,0};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n;
ll a[300100];
priority_queue<ll,vector<ll>,greater<ll>> former;
priority_queue<ll> latter;
ll sum_f[100100]={};
ll sum_l[100100]={};
ll ans=-INFl;
int main(){
	cin>>n;
	REP(i,3*n)cin>>a[i];
	REP(i,n){
		former.push(a[i]);
		sum_f[0]+=a[i];
	}
	for(int i=2*n;i<3*n;i++){
		sum_l[0]+=a[i];
		latter.push(a[i]);
	}
	for(int i=n;i<2*n;i++){
		former.push(a[i]);
		sum_f[i-n+1]=sum_f[i-n]+a[i]-former.top();
		former.pop();
	}
	for(int i=2*n-1;i>=n;i--){
		latter.push(a[i]);
		sum_l[2*n-i]=sum_l[2*n-i-1]+a[i]-latter.top();
		latter.pop();
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,(sum_f[i]-sum_l[n-i]));
	}
	cout<<ans<<endl;
	return 0;
}