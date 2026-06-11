#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
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
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

void solve(){
	LL N;
	cin >> N;
	LL NN = N+1;
	deque<int> bits;
	deque<int> Rans;
	LL temp = NN;
	while( temp ){//NNの2進数表現を計算
		bits.push_front( temp&1 );
		temp >>= 1;
	}

	Rans.push_back(1);
	int num = 2;//次にRansへ追加する数
	//LL X = 2;
	int size = bits.size();
	for(int i=1;i<size;++i){
		if( bits[i] == 1 ){
			Rans.push_front( num );
			++num;
		}
		if( i+1 < size ){
			Rans.push_back( num );
			++num;
		}
	}
	size = Rans.size();
	cout << 2*size << endl;
	for(int i=0;i<size;++i){
		if( i ) cout << " ";
		cout << i+1;
	}
	for(int i=0;i<size;++i){
		cout << " ";
		cout << Rans[i];
	}
	cout << endl;
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
