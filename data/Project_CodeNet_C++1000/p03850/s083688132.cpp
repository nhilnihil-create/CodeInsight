#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <bitset>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
//#include <time.h>
#include <ctime>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
#define ALL(X) X.begin(), X.end()
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef std::pair<LL,LL> PLL;//
typedef std::pair<int,int> PII;//
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)1e18+20;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

/*
thx
http://kmjp.hatenablog.jp/entry/2017/01/11/1030
*/
void solve(){
	int N;
	cin >> N;
	vector<bool> OP(N);
	vector<LL> A(N);
	OP[0] = false;
	cin >> A[0];
	for(int i=1;i<N;++i){
		char op;
		cin >> op >> A[i];
		OP[i] = (op=='-');
	}
	vector< vector<LL> > dp(N+1,vector<LL>(3,-LINF));
	dp[0][0] = 0;
	for(int i=0;i<N;++i){
		if( OP[i] == false){//'+' 開かない。閉じれる
			dp[i+1][2] = dp[i][2] + A[i];
			//dp[i+1][2]から一つ閉じるとdp[i+1][1]にいける
			dp[i+1][1] = max(dp[i+1][2], dp[i][1] - A[i]);
			//dp[i+1][1]から一つ閉じるとdp[i+1][0]にいける
			dp[i+1][0] = max(dp[i+1][1], dp[i][0] + A[i]);
		}else{//'-':必ず開き括弧を前につける。必ず開く。閉じれる
			dp[i+1][2] = dp[i][1] + A[i];
			//LL res1 = max(dp[i][0],dp[i][2]);//括弧をすべて閉じる
			LL res1 = dp[i][0];//前の項で括弧全部閉じてる
			dp[i+1][1] = max(dp[i+1][2], res1 - A[i]);
			dp[i+1][0] = max(dp[i+1][1], dp[i][1] + A[i]);
		}
	}
	LL ans = dp[N][0];//ここにまとまってる
	cout << ans << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()