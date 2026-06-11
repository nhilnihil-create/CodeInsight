#pragma warning(disable:4996)
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)
#define TPL template
#define TNM typename

using ll = long long;
using ull = unsigned long long;
TPL<TNM T> using vec = vector<T>;
TPL<TNM T> using vec2 = vec<vec<T>>;
TPL<TNM T> using vec3 = vec<vec2<T>>;
TPL<TNM T> using vec4 = vec<vec3<T>>;
TPL<TNM T> using vec5 = vec<vec4<T>>;

TPL<TNM V, TNM H> void resize(vector<V>& v, const H h) { v.resize(h); }
TPL<TNM V, TNM H, TNM ... T> inline void resize(vector<V>& v, const H& h, const T ... t) { v.resize(h); for (auto& _v : v) resize(_v, t ...); }
TPL<TNM V, TNM T> void fill(V& x, const T& val) { x = val; }
TPL<TNM V, TNM T> inline void fill(vector<V>& vec, T& val) { for (auto& v : vec) fill(v, val); }
TPL<TNM T> inline void UNIQUE(vector<T>& vec) { sort(ALL(vec)); vec.erase(unique(ALL(vec)), vec.end()); }

//バグあり
class YukiIO {
	bool f = false; //改行が残っている否か
	char* buff;
	int sbuff;
	string format;
public:
	YukiIO(int s_, int pre_) { sbuff = s_; buff = new char[s_]; format = "%." + to_string(pre_) + "lf"; }
	~YukiIO() { delete buff; }
	//--------------input---------------
	inline void get(int &i_) { f = true; scanf("%d", &i_); }
	inline void get(long long &l_) { f = true; scanf("%lld", &l_); }
	inline void get(double &d_) { f = true; scanf("%lf", &d_); }
	inline void get(float &f) { f = true; scanf("%f", &f); }
	inline void get(char &c_) {
		if (f)scanf("%*c%c", &c_);
		else scanf("%c", &c_);
		f = true;
	}
	inline void get(char* s_) { f = true; scanf("%s", s_); }
	inline void get(string &s_) { f = true; scanf("%s", buff); s_ = string(buff); }
	template <typename HEAD, typename ...TAIL>inline void get(HEAD& head, TAIL& ...tails) {
		get(head);
		get(tails...);
	}
	template <typename T> inline void get(vector<T>& v_) {
		for (int i = 0; i < v_.size(); ++i) get(v_[i]);
	}
	inline void getl(string& s_) {
		if (f) { char dm; scanf("%c", &dm); }
		fgets(buff, sbuff, stdin);
		s_ = string(buff);
		f = false;
	}
	template <typename ...ARGS> inline void getf(const char* format, ARGS& ... args) {
		if (f)scanf("%*c%[^\n]", buff);
		else scanf("%[^\n]", buff);
		sscanf(buff, format, &args...);
		f = true;
	}
	//--------------outut---------------
	inline void print(bool b_) { printf("%s", b_ ? "true" : "false"); }
	inline void print(int i_) { printf("%d", i_); }
	inline void print(unsigned int i_) { printf("%d", i_); }
	inline void print(long long l_) { printf("%lld", l_); }
	inline void print(unsigned long long l_) { printf("%lld", l_); }
	inline void print(double d_) { printf(format.data(), d_); }
	inline void print(float f) { printf("%f", f); }
	inline void print(char c_) { printf("%c", c_); }
	inline void print(char* s_) { printf("%s", s_); }
	inline void print(string &s_) { printf("%s", s_.data()); }
	inline void print(const char* s_) { printf("%s", s_); }
	template <typename T> inline void print(vector<T>& v) {
		print(v[0]);
		for (int i = 1; i < v.size(); ++i) {
			putchar(' '); print(v[i]);
		}
	}
	inline void println() { puts(""); }
	template <typename T> inline void println(vector<T>& v) { for (int i = 0; i < v.size(); ++i) println(v[i]); }
	template <typename HEAD, typename ...TAIL>inline void print(HEAD head, TAIL ...tails) {
		print(head);
		print(tails...);
	}
	template <typename ...ARGS>inline void println(ARGS ...args) {
		print(args...);
		puts("");
	}
};

YukiIO io(114514, 12);

ll N, A, B;
vec<ll> Ho;

inline bool check(int n) {
	ll C = A - B;
	vec<ll> H = Ho;
	ll res = 0;
	REP(i, N) {
		H[i] -= B * n;
		if (H[i] > 0) {
			H[i] = (H[i] + C - 1) / C;
		}
		else {
			H[i] = 0;
		}
		res += H[i];
	}
	return res <= n;
}

int main(void) {
	io.get(N, A, B);
	resize(Ho, N);

	REP(i, N) {
		io.get(Ho[i]);
	}

	ll ok = 1000'000'000;
	ll ng = -1;

	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (check(mid)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	
	io.println(ok);

	return 0;
}