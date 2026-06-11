#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	LL N;
	cin >> N;
	LL A[100000];
	LL sum = 0;
	for(int i=0; i<N; i++){
		cin >> A[i];
		sum += A[i];
	}

	if(sum % (N*(N+1)/2) != 0){
		cout << "NO" << endl;
		return 0;
	}
	LL t = sum / (N*(N+1)/2);

	multiset<LL> st;
	for(int i=1; i<N; i++) st.insert(A[i]-A[i-1]-t);
	st.insert(A[0]-A[N-1]-t);

	auto itr = st.begin();
	LL bef = *itr;
	t -= (-*itr)/N;
	itr++;
	while(itr != st.end()){
		if(abs(*itr-bef)%N != 0){
			cout << "NO" << endl;
			return 0;
		}
		t -= (-*itr)/N;
		if(t < 0){
			cout << "NO" << endl;
			return 0;
		}
		bef = *itr;
		itr++;
	}
	if(t > 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	return 0;
}
