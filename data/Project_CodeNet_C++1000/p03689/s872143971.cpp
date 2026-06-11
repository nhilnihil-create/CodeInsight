////////////////////////////////////////////
///                                      ///
///        Template ver. 1.2. rapel      ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 500;
int field[N + 5][N + 5];

const int MULTI = 2300;

void hora(int tc) {
	int R, C, r, c;
	cin>>R>>C>>r>>c;
	ll total = 0;
	int p1 = -(r * c - 1) * MULTI - 1;
	for(int i = 1;i <= R;i++) {
		for(int j = 1;j <= C;j++) {
			if(i % r == 0 && j % c == 0) field[i][j] = p1;
			else field[i][j] = MULTI;
			total += field[i][j];
		}
	}
	if(total > 0) {
		cout<<"Yes"<<endl;
		for(int i = 1;i <= R;i++) {
			for(int j = 1;j <= C;j++) {
				if(j != 1) cout<<" ";
				cout<<field[i][j];
			}
			cout<<endl;
		}
	} else cout<<"No"<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
