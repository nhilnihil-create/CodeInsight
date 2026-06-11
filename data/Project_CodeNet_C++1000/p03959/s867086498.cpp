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

int n;
int t[100100];
int a[100100];
int dh[100100];
int uh[100100];

int main(){
	cin>>n;
	REP(i,n){
		cin>>t[i];
		if(i!=0){
			if(t[i-1]>t[i]){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	REP(i,n){
		cin>>a[i];
		if(i!=0){
			if(a[i-1]<a[i]){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	REP(i,n){
		dh[i]=-1;
		uh[i]=-1;
	}
	dh[0]=t[0];
	FOR(i,1,n){
		if(t[i-1]<t[i]){
			dh[i]=t[i];
		}else{
			uh[i]=t[i];
		}
	}
	if(dh[n-1]!=-1){
		if(dh[n-1]!=a[n-1]){
			cout<<0<<endl;
			return 0;
		}
	}
	dh[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			if(dh[i]==-1){
				dh[i]=a[i];
			}else{
				if(dh[i]!=a[i]){
					cout<<0<<endl;
					return 0;
				}
			}
		}else{
			if(uh[i]==-1){
				if(dh[i]>a[i]){
					cout<<0<<endl;
					return 0;
				}
			}else{
				uh[i]=min(uh[i],a[i]);
			}
		}
	}
	ll ans=1;
	REP(i,n){
		
		if(dh[i]==-1){
			ans*=uh[i];
			ans%=MOD;
		}
	}/*
	REP(i,n)cout<<dh[i]<<" ";
	cout<<endl;
	
	REP(i,n)cout<<uh[i]<<" ";
	cout<<endl;*/
	
	cout<<ans<<endl;
	return 0;
}