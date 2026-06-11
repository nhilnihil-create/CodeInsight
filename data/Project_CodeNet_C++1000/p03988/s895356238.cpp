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

const int N = 100;
int occ[N + 5];

void hora(int tc) {
	int n;
	cin>>n;
	int maxi = 0;
	for(int i = 1;i <= n;i++) {
		int x;
		cin>>x;
		occ[x]++;
		maxi = max(maxi, x);
	}
	int length = maxi + 1;
//	cout<<maxi<<" "<<length<<endl;
	bool bisa = 1;
	for(int i = maxi;i >= length / 2;i--) {
		if(i == length / 2) {
			if(length % 2 == 1) {
				if(occ[length / 2] != 1) bisa = 0;
			} else {
				if(occ[length / 2] != 2) bisa = 0;
			}
		} else {
			if(occ[i] < 2) bisa = 0;
			occ[i] -= 2;
		}
	}
	if(bisa) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
