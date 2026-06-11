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
int mdx[4]={0,1,0,-1},mdy[4]={-1,0,1,0};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll N,W;
ll w[110],v[110];
vector<ll> v1[4];
ll num[4]={};
int main(){
	cin>>N>>W;
	REP(i,N){
		cin>>w[i]>>v[i];
		v1[w[i]-w[0]].push_back(v[i]);
		num[w[i]-w[0]]++;
	}
	REP(i,4)sort(v1[i].begin(),v1[i].end(),greater<ll>());
	ll dp[num[0]+1][num[1]+1][num[2]+1][num[3]+1];
	REP(i,num[0]+1)
		REP(j,num[1]+1)
			REP(k,num[2]+1)
				REP(l,num[3]+1)
				dp[i][j][k][l]=0;
	FOR(i,1,num[0]+1){
		dp[i][0][0][0]=dp[i-1][0][0][0]+v1[0][i-1];
	}
	REP(i,num[0]+1){
		FOR(j,1,num[1]+1){
			dp[i][j][0][0]=dp[i][j-1][0][0]+v1[1][j-1];
		}
	}
	REP(i,num[0]+1){
		REP(j,num[1]+1){
			FOR(k,1,num[2]+1){
				dp[i][j][k][0]=dp[i][j][k-1][0]+v1[2][k-1];
			}
		}
	}
	REP(i,num[0]+1){
		REP(j,num[1]+1){
			REP(k,num[2]+1){
				FOR(l,1,num[3]+1){
					dp[i][j][k][l]=dp[i][j][k][l-1]+v1[3][l-1];
				}
			}
		}
	}
	ll ans=0;
	REP(i,num[0]+1){
		REP(j,num[1]+1){
			REP(k,num[2]+1){
				REP(l,num[3]+1){
					if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3)>W)continue;
					ans=max(ans,dp[i][j][k][l]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
	