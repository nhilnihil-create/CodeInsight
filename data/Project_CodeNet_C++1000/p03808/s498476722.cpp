#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<31)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
//int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


ll n;
ll a[100100];
ll b[100100];
ll sum=0;

int main(){
	cin>>n;
	REP(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	ll nls=n*(n+1)/2;
	if(sum%nls!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	nls=sum/nls;
	b[0]=a[0]-a[n-1];
	for(int i=0;i<n-1;i++){
		b[i+1]=a[i+1]-a[i];
	}
	for(int i=0;i<n;i++){
		b[i]-=nls;
		if(b[i]%n!=0){
			cout<<"NO"<<endl;
			return 0;
		}
		b[i]/=n;
		b[i]*=(-1);
		if(b[i]<0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		nls-=b[i];
	}
	if(nls==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}