#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define rrep(i, n) for (int i=(int)n-1;i>=0;--i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)r;++i)
#define rrange(i, l, r) for (int i=(int)r-1;i>=(int)l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;
using ld=long double;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int mod = TEN(9)+7;

signed main()
{
	int N, M; cin >> N >> M;
	swap(N, M);
	int ans = 0;
	int a = min(M, N / 2);
	ans += a;
	N -= a * 2, M -= a;
	ans += N / 4;

	cout << ans << endl;
}


