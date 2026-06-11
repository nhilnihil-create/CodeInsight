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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+1;
int a[L];
bool f(int i,int j){
	while(1){
		if(i+1<a[j+1]){
			i++;
			j++;
			continue;
		}
		if(i+1<a[j]){
			if((a[j]-i)%2==0){
				return false;
			}
		}
		int k=0;
		while(i<a[j]){
			k++;
			j++;
		}
		return k%2==1;
	}
}

int main() {
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N,greater<int>());
	if(f(0,0)){
		cout << "Second" << endl;
		return 0;
	}

	if(a[0]>1&&f(1,0)){
		cout << "First" << endl;
		return 0;
	}
	if(N>1&&f(0,1)){
		cout << "First" << endl;
		return 0;
	}
	cout << "Second" << endl;

	return 0;
}

