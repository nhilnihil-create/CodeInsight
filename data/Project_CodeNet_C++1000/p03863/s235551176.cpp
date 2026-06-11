#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a <= b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }


//25m
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	if (s.size() & 1) {
		if (s[0] == s.back()) cout << "Second" << endl;
		else cout << "First" << endl;
	}
	else {
	  if (s[0] == s.back()) cout << "First" << endl;
		else cout << "Second" << endl;
	}
}