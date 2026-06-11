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

const int N = 1e5;
int arr[N + 5];

void hora(int tc) {
	int n;
	cin>>n;
	int maxi = 0;
	for(int i = 0;i < n;i++) {
		cin>>arr[i];
		maxi = max(maxi, arr[i]);
	}
	bool bisa = true;
	int independent = 0;
	for(int i = 0;i < n;i++) {
		if(maxi - arr[i] >= 2) bisa = false;
		else if(maxi - arr[i] == 1) independent++;
	}
	if(!bisa) {
		cout<<"No"<<endl;
		return ;
	}
	int sisa = n - independent;
	if(sisa == n) {
		if(maxi>= 1 && maxi <= n / 2 || maxi + 1 == n) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	} else {
		if(sisa == 1 || independent + 1 > maxi || maxi > independent + sisa / 2) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
