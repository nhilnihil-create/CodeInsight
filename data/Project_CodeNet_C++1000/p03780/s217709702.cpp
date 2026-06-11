#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define gridif(a,x,b) if((a)<=(x)&&(x)<(b))

using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
const int mod=1000000007;

int digitsum(int n,int b){
	if(b<2) return -1;
	if(n<b) return n;
	return digitsum(n/b,b)+n%b;
}
int mpow(int a,int x);
int m_inv(int n);
vector<int> split(int n,int a);
string xal_number(int n,int x);
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
class Factorial{
private:
	vector<int> fac;
public:
	Factorial(int N){
		fac.push_back(1);
		rep(i,N) fac.push_back(fac[i]*(i+1)%mod);
	}
	int fact(int a){return fac[a];}
	int ifac(int a){return m_inv(fac[a]);}
	int cmb(int n,int r);
};
struct UnionFind {
    vector<int> par; // 親ノード
    UnionFind(int n = 1) { init(n);}
    void init(int n = 1) {
        par.resize(n);
        rep(i,n) par[i] = -1;
    }
    int root(int x) {
        if (par[x] <0) return x;
        else return par[x] = root(par[x]);      
    }
    int size(int x){ return -par[root(x)];}
    bool issame(int x, int y) {return root(x)==root(y);}
    bool connect(int x, int y);
};

signed main(){
	int N,K;
	cin>>N>>K;
	vector<int> a(N);
	rep(i,N) cin>>a[i];
	sort(All(a));
	int inf=1<<20;
	
	//dp[i][j]=i番目のカードまでで総和をjにできるか
	int l=-1,r=N;
	while(l<r-1){//不必要なカードの最後尾を探す
		Graph dp(N+1,vector<int>(K,0));
		dp[0][0]=1;
		int out=(l+r)/2;
		if(a[out]>=K){//必要ならば右を寄せる
			r=out;
			continue;
		}
		rep(i,N) rep(j,K){
			if(j-a[i]>=0)dp[i+1][j]=max(dp[i][j-a[i]],dp[i][j]);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(i==out) dp[i+1][j]=dp[i][j];
		}
		rep(i,a[out]) if(dp[N][K-a[out]+i]==1) r=out;
		if(r!=out) l=out;
		
	}
	cout<<r<<endl;
}