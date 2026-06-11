// need
#include <iostream>
#include <algorithm>

// data structure
#include <bitset>
//#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <array>
//#include <tuple>
//#include <unordered_map>
#include <unordered_set>
#include <complex>
//#include <deque>
#include <valarray>

// stream
//#include <istream>
//#include <sstream>
//#include <ostream>
//#include <fstream>

// etc
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
//#include <typeinfo>
#include <chrono>
#include <random>
#include <numeric>

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int i=0; i<n; ++i){MACRO_VEC_ROW_Scan(i, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest&...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest&...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;

// output
#define OUT(d) std::cout<<d;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<d;
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<d;
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(i, n) std::cout<<(i + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(d) {std::cerr << #d << "\t:" << d << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}

// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define FORLL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORLL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPLL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPLL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
template<typename T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<typename T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}
void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n"; }

// test
template<class T> std::vector<std::vector<T>> VV(int n) {
	return std::vector<std::vector<T>>(n);
}
template<class T> std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
	return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

// type/const

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;                          // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double EPS = 1e-7;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

char col[] = { 'R', 'G', 'B', 'Y' };

signed main() {
	INIT;
	VAR(int, h, w, d);
	if (d == 2) {
		int W = w * 20 + 100000;
		std::vector<std::vector<char>> ans(h, std::vector<char>(W, ' '));
		REP(i, h) {
			REP(j, W) {
				ans[i][(j + 3 * i) % W] = col[(j / 2) % 4];
			}
		}
		REP(i, h) {
			REP(j, w) {
				OUT(ans[i][j + 50000]);
			}BR;
		}
		return 0;
	}
	int H = h * 3 + 1000;
	int W = w * 3 + 1000;
	int D = d / 2;
	std::vector<std::vector<char>> ans(H, std::vector<char>(W, ' '));
	if (d % 2 == 1) {
		// R, B
		for (int y = 0; y < H; y += d) {
			for (int x = 0; x < W; x += d) {
				int t = (x + y) / d;
				char c = (t % 2 == 0 ? 'R' : 'B');
				FOR(i, -D, D + 1) {
					int dd = D - (int)std::abs(i);
					FOR(j, -dd, dd + 1) {
						if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
						ans[i + y][j + x] = c;
					}
				}
			}
		}
		// G, Y
		for (int y = D; y < H; y += d) {
			for (int x = D; x < W; x += d) {
				int t = (x - D + y - D) / d;
				char c = (t % 2 == 0 ? 'G' : 'Y');
				ans[y][x] = c;
				FOR(i, -(D - 1), D + 1) {
					int dd = D - (int)std::abs(i);
					if (i <= 0) {
						FOR(j, -(dd - 1), dd + 1) {
							if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
							ans[i + y][j + x] = c;
						}
					}
					else {
						FOR(j, -dd, dd + 2) {
							if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
							ans[i + y][j + x] = c;
						}
					}
				}
			}
		}
	}
	else { // d % 2 == 0
		// R, B
		for (int y = 0; y < H; y += d) {
			for (int x = 0; x < W; x += d) {
				int t = (x + y) / d;
				char c = (t % 2 == 0 ? 'R' : 'B');
				FOR(i, -(D - 1), D + 1) {
					int dd = D - (int)std::abs(i);
					if (i <= 0) {
						FOR(j, -(dd - 1), dd + 1) {
							if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
							ans[i + y][j + x] = c;
						}
					}
					else {
						FOR(j, -dd, dd + 2) {
							if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
							ans[i + y][j + x] = c;
						}
					}
				}
			}
		}
		// G, Y
		for (int y = D; y < H; y += d) {
			for (int x = D; x < W; x += d) {
				int t = (x - D + y - D) / d;
				char c = (t % 2 == 0 ? 'G' : 'Y');
				ans[y][x] = c;
				FOR(i, -(D - 1), D) {
					int dd = D - (int)std::abs(i);
					FOR(j, -(dd - 1), dd + 1) {
						if (!IN(0, i + y, H) || !IN(0, j + x, W)) continue;
						ans[i + y][j + x] = c;
					}
				}
			}
		}
	}
	REP(i, h) {
		REP(j, w) {
			OUT(ans[i + 200][j + 200]);
		}BR;
	}
	return 0;
}