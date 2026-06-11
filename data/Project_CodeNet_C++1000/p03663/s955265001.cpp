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

LL test = 120;
string getString(LL num){
	stringstream ss;
	ss << num;
	return ss.str();
}

bool query(LL num){
	cout << "? " << num << endl;
//*
	string res;
	cin >> res;
	return (res[0]=='Y');
//*/
	string tStr = getString( test );
	string nStr = getString( num );
	bool B1 = false;
	bool B2 = false;
	if( num <= test && nStr <= tStr ){
		B1 = true;
	}
	if( num > test && nStr > tStr ){
		B2 = true;
	}
	return B1^B2;
}
void pow10(){//10^n
	LL base = 2;
	while( query(base) == false ){
		base *= 10;
	}
	cout << "! " << base/2 << endl;
}
void solve(){
	int base = (int)1e9;
	
	if( query( base ) ){
		pow10();
		return;
	}

	//桁数の決定
	int keta = 9;
	base /= 10;
	while( query( base ) == false ){
		--keta;
		base /= 10;
	}

	//
	LL H,L;
	L = base;
	H = base*10-1;
	
	while(H-L>1){
		LL mid = (L+H)/2;
		if( query( mid*10 ) ){
			H = mid;
		}else{
			L = mid;
		}
	}
	
	cout << "! " << H << endl;
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
