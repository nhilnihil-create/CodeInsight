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

int n,k;
int a[5010];
bool dp[5010];
int main(){
	cin>>n>>k;
	REP(i,n)cin>>a[i];
	sort(a,a+n);
	int ub=-1;
	int lb=n;
	while(lb-ub>1){
		int mid=(ub+lb)/2;
		REP(i,5010)dp[i]=false;
		dp[0]=true;
		for(int i=0;i<n;i++){
			if(mid==i)continue;
			for(int j=k-1;j>=0;j--){
				if(a[i]+j<k&&dp[j]){
					dp[j+a[i]]=true;
					//cout<<" "<<i<<" "<<j<<" "<<j+a[i]<<endl;
				}
			}
		}
		bool judge=0;
		if(a[mid]>=k)judge=1;
		else{
			for(int i=k-a[mid];i<k;i++){
				if(dp[i])judge=1;
			}
		}
		if(judge)lb=mid;
		else ub=mid;
		//cout<<"mid:"<<mid<<endl;
		//REP(i,20)cout<<dp[i]<<endl;
	}
	cout<<ub+1<<endl;
	return 0;
}