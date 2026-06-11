#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll mod=1e9+7;
void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
ll dp[5001][5001];
int main(){
	int N,K;
	string s;
	cin>>N>>s;
	K=s.size();
	dp[0][0]=1;
	rep(i,N) rep(j,i+1) if(dp[i][j]){
		add(dp[i+1][j+1],dp[i][j]*2);
		add(dp[i+1][max(j-1,0)],dp[i][j]);
	}
	ll i2=(mod+1)/2;
	ll ans=dp[N][K];
	rep(i,K) ans=ans*i2%mod;
	cout<<ans<<endl;
}