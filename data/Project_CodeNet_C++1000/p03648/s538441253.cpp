#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main() {
	LL K;
	cin >> K;
	if(K%2==0){
		if(1+K/2<=1e16){
			cout << 2 << endl;
			cout << 1+K/2 << " " << 1+K/2 << endl;
			return 0;
		}
	}
	else{
		if(1+(K+1)/2+1<=1e16){
			cout << 2 << endl;
			cout << 1+(K+1)/2-2 << " " << 1+(K+1)/2+1 << endl;
			return 0;
		}
	}

	LL U;
	if(K%50==0){
		U=K;
	}
	else{
		U=K+50-K%50;
	}
	vector<LL> v;
	for(int i=0;i<50;i++){
		v.push_back(49+U/50);
	}
	for(int i=0;i<U-K;i++){
		sort(v.begin(),v.end());
		for(int j=0;j<48;j++){
			v[j]++;
		}
		v[49]-=50;
	}
	cout << 50 << endl;

	auto sp="";
	for(int i=0;i<50;i++){
		cout << sp << v[i];
		sp=" ";
	}
	cout << endl;

	return 0;
}

