////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
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
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N =  1e5;
const int M = 18;
int sparse[M + 2][N + 5];
int arr[N + 5];

void hora(int tc) {
	int n, l;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>arr[i];
	cin>>l;
	arr[n + 1] = 1e9;
	int j = 1;
	for(int i = 1;i <= n;i++) {
		while(j != n + 1 && arr[j] - arr[i] <= l) j++;
		j--;
		sparse[0][i] = j;
	}
	for(int i = 1;i <= M;i++) for(int j = 1;j <= n;j++) sparse[i][j] = sparse[i-1][sparse[i-1][j]];
	int q;
	cin>>q;
	while(q--) {
		int l,r;
		cin>>l>>r;
		if(l > r) swap(l,r);
		int tot = 0;
		for(int i = M;i >= 0;i--) {
			if(sparse[i][l] < r) {
				l = sparse[i][l];
				tot += (1<<i);
			}
		}
		tot++;
		cout<<tot<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


