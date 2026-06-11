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

ll n;
ll a[20100],b[20100];
ll p[20100];
int main(){
	cin>>n;
	REP(i,n){
		int pq;
		cin>>pq;
		pq--;
		p[pq]=(i+1);
	}
	REP(i,n){
		a[i]=(i+1)*(3e4);
	}
	REP(i,n){
		b[n-i-1]=(i+1)*(3e4);
	}
	REP(i,n){
		b[i]+=p[i];
	}
	REP(i,n)
		cout<<a[i]<<" ";
	cout<<endl;
	REP(i,n)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}