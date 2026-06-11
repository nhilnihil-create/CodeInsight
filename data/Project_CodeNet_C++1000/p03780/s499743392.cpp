#include <bits/stdc++.h>

#define int long long

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a, i##_len=(b); i<i##_len; i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define all(box) box.begin(), box.end()

using namespace std;

using P = pair<int,int>;
using ll = long long;

const long long INF = LLONG_MAX/3;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind{
	std::vector<int> par,siz;
	void init(int n){
		par.resize(n);
		for(int i=0;i<n;i++)par[i]=i;
		siz.resize(n,1);
	}
	UnionFind(int n){
		init(n);
	}
	int root(int n){
		if(par[n]==n)return n;
		else return par[n]=root(par[n]);
	}
	bool issame(int x,int y){
		return (root(x)==root(y));
	}
	bool marge(int a,int b){
		if(issame(a,b))return false;
		else{
			a=root(a),b=root(b);
			if(siz[a]<siz[b])swap(a,b);
			siz[b]+=siz[a];
			par[a]=par[b];
			return true;
		}
	}
	int size(int n){
		return siz[root(n)];
	}
};

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long i,long long j){
    return i*(j/gcd(i,j));
}

const int MOD=1e9+7;
long long fac[510000], finv[510000], inv[510000];
long long MAX=510000;
bool COMinited=false;
long long COM(int n, int k){
	if(COMinited==false){
		fac[0] = fac[1] = 1;
    	finv[0] = finv[1] = 1;
    	inv[1] = 1;
    	for (int i = 2; i < MAX; i++){
        	fac[i] = fac[i - 1] * i % MOD;
        	inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        	finv[i] = finv[i - 1] * inv[i] % MOD;
    	}
		COMinited=true;
	}
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
bool dp[5010][5010]={},dpr[5010][5010]={};
signed main(){
	int n,k;
	cin>>n>>k;
	int a[5010];
	rep(i,n){
		cin>>a[i];
	}
	dp[0][0]=true;
	dpr[0][0]=true;
	rep(i,1,n+1){
		rep(j,k)dp[i][j]=dp[i-1][j];
		rep(j,k){
			if(dp[i-1][j]){
				if(j+a[i-1]<k)dp[i][j+a[i-1]]=true;
			}
		}
	}
	rep(i,1,n+1){
		rep(j,k)dpr[i][j]=dpr[i-1][j];
		rep(j,k){
			if(dpr[i-1][j]){
				if(j+a[n-i]<k)dpr[i][j+a[n-i]]=true;
			}
		}
	}
	int cnt=0;
	rep(i,n){
		int mn=INF;
		vector<int> s,t;
		rep(j,k){
			if(dp[i][j])s.push_back(j);
			if(dpr[n-i-1][j])t.push_back(j);
		}
		/*cout<<"s:";
		rep(j,s.size())cout<<s[j]<<" ";
		cout<<endl;
		cout<<"t:";
		rep(j,t.size())cout<<t[j]<<" ";
		cout<<endl;*/
		rep(j,s.size()){
			int l=lower_bound(t.begin(),t.end(),k-s[j]-a[i])-t.begin();
			if(l<t.size())chmin(mn,s[j]+a[i]+t[l]);
		}
		if(mn==INF||mn-a[i]>=k)cnt++;
	}
	cout<<cnt<<endl;
}