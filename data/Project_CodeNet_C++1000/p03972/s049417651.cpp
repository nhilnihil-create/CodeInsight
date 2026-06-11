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

int w,h;
vector<Pi> vp;
ll ans=0;
int main(){
	cin>>w>>h;
	int cw,ch;
	cw=w+1;
	ch=h+1;
	REP(i,w){
		int w1;
		cin>>w1;
		vp.push_back(Pi(w1,0));
	}
	REP(i,h){
		int h1;
		cin>>h1;
		vp.push_back(Pi(h1,1));
	}
	sort(vp.begin(),vp.end());
	REP(i,vp.size()){
		if(vp[i].second==0){
			ans+=(ll)ch*vp[i].first;
			cw--;
		}else{
			ans+=(ll)cw*vp[i].first;
			ch--;
		}
	}
	cout<<ans<<endl;
	return 0;
}