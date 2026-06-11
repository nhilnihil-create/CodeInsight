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


int n,m;
int a[100100],b[100100];
int alr[100100];
int ans[400100];
int st,en;
vector<int> edge[100100];
int check(int t){
	for(int i=0;i<edge[t].size();i++){
		if(!alr[edge[t][i]]){
			return edge[t][i];
		}
	}
	return -1;
}
int main(){
	REP(i,400100)ans[i]=-1;
	cin>>n>>m;
	REP(i,m){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
	}
	st=200000,en=200001;
	ans[st]=a[0];
	ans[en]=b[0];
	alr[a[0]]=1;
	alr[b[0]]=1;
	while(1){
		int t1=check(ans[st]);
		if(t1!=-1){
			st--;
			ans[st]=t1;
			alr[t1]=1;
		}
		int t2=check(ans[en]);
		if(t2!=-1){
			en++;
			ans[en]=t2;
			alr[t2]=1;
		}
		if(check(ans[st])==-1&&check(ans[en])==-1)break;
	}
	cout<<en-st+1<<endl;
	for(int i=st;i<=en;i++){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;
	return 0;
}