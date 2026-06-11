#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1'000'000'007;
const ll inf=1'000'000'000'000'000'00;
const int INF=1'000'000'000;
const double EPS=1e-10;
const double PI=acos(-1);

int dp[50][500][500];

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,ma,mb;
	cin>>n>>ma>>mb;
	vector<int> a(n),b(n),c(n);
	rep(i,n){
		cin>>a[i]>>b[i]>>c[i];
	}
	rep(i,50)rep(j,500)rep(k,500) dp[i][j][k]=INF;
	dp[0][0][0]=0;
	rep(i,n)rep(j,500)rep(k,500){
		if(dp[i][j][k]==INF) continue;
		chmin(dp[i+1][j][k],dp[i][j][k]);
		chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
	}
	int ans=INF;
	FOR(j,1,500)FOR(k,1,500){
		if(j*mb==k*ma){
			chmin(ans,dp[n][j][k]);
		}
	}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
}