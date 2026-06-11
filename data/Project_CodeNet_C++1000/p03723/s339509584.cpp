#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

void out(int a, int b, int c) {
	cout << "a:" << a << " b:"  << b << " c:" << c << endl;
}

bool check(int a, int b, int c) {
	if(a & 1) return false;
	if(b & 1) return false;
	if(c & 1) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 100;
	int ans = 0;
	while(cnt--) {
		if(!check(a, b, c)) break;
		ans++;
		int na = (b + c) / 2;
		int nb = (c + a) / 2;
		int nc = (a + b) / 2;
		a = na, b = nb, c = nc;
	}
	cout << (ans > 90 ? - 1 : ans) << endl;
}