#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#ifdef LOCAL_DEV
	#define debug(var) std::cout<<#var" = "<<var<<std::endl
#else
	#define debug(var)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	template<typename T> class dvector : public std::vector<T> {
	public:
		dvector() : std::vector<T>() {}
		explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n,value) {}
		dvector(const std::vector<T>& v) : std::vector<T>(v) {}
		dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
		dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
		dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
		T& operator[](size_t n) {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
		const T& operator[](size_t n) const {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
	};
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool &b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, std::pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
	template<typename T> std::ostream& operator<<(std::ostream& s, dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	#define vector dvector
	#define bool dbool
#endif
//#define int long long
using bll = boost::multiprecision::cpp_int;
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
#define p(var) std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << (i==N-1 ? '\n' : ' '); }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline T1 power(T1 x, T2 n){ return n ? power(x*x%MOD,n/2)*(n%2?x:1)%MOD : 1; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

/*-----8<-----8<-----*/

signed main() {
	ll N,Ma,Mb;
	cin>>N>>Ma>>Mb;
	vector<ll> a(N,0),b(N,0),c(N,0);
	ll SIZE=400;
	ll INFVAL=99999999;
	vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(SIZE+1, vector<ll>(SIZE+1, INFVAL)));
	rep(i,N){
		cin>>a[i]>>b[i]>>c[i];
		dp[i][a[i]][b[i]]=c[i];
	}
	
	for(ll i=1;i<N;i++){
		rep(j,SIZE+1)rep(k,SIZE+1){
			if(dp[i-1][j][k]<INFVAL){
				chmin(dp[i][j][k],dp[i-1][j][k]);
				chmin(dp[i][j+a[i]][k+b[i]],dp[i-1][j][k]+c[i]);
			}
		}
	}
	debug(dp);

	ll minval=INFVAL;
	ll ma=Ma,mb=Mb;
	while(ma<=SIZE && mb<=SIZE){
		chmin(minval,dp[N-1][ma][mb]);
		ma+=Ma,mb+=Mb;
	}
	if(minval==INFVAL){
		p(-1);
	}else{
		p(minval);
	}
	
	return 0;
}
