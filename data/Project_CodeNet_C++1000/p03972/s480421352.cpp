#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << std::endl; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) std::cerr << std::boolalpha << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); std::cerr << std::noboolalpha;
#else
	#define debug(...)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	template<typename T> class dvector : public std::vector<T> {
	public:
		dvector() : std::vector<T>() {}
		explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
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
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}" << std::endl; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { 
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main(){ signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
#define p(var) std::cout<<var<<std::endl
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

/*-----8<-----template-----8<-----*/

/*-----8<-----library-----8<-----*/

const ll W_MAX = 1e5;
const ll H_MAX = 1e5;
const ll P_I_MAX = 1e8;
const ll Q_J_MAX = 1e8;

ll W, H;
vector<ll> p;
vector<ll> q;

void solve() {
	scanf("%lld%lld", &W, &H);
	p.assign(W, 0);
	rep(i, W) scanf("%lld", &p[i]);
	q.assign(H, 0);
	rep(i, H) scanf("%lld", &q[i]);

	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, function<bool(pair<ll,ll>,pair<ll,ll>)>>que(
		[](const pair<ll,ll> &x, const pair<ll,ll> &y){
			return x.first > y.first;
		}//xの優先度が低いときに対してtrueを返すこと この場合昇順優先
	);
	rep(i,W){
		que.push({p[i],0});
	}
	rep(i,H){
		que.push({q[i],1});
	}

	ll h=W+1,w=H+1;
	ll ans=0;
	ll c=(1+H)*(1+W)-1;
	while(c>0){
		pair<ll,ll> p=que.top();
		que.pop();
		if(p.second==0){
			debug(p,w);
			ans+=p.first*w;
			c-=w;
			h--;
		}else{
			debug(p,h);
			ans+=p.first*h;
			c-=h;
			w--;
		}
		debug(c);
	}
	printf("%lld\n", ans);
}

// https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c
signed main() {
	solve();
	return 0;
}
