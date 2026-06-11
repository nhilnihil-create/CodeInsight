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

const LL M=1e9;
int main() {
	LL low=1;
	LL hi=10;
	char a;
	while(1){
		if(low==M){
			int v=1;
			while(v<M){
				cout << "? " << v+1 << endl;
				cin >> a;
				if(a=='Y'){
					break;
				}
				v*=10;
			}
			cout << "! " << v << endl;
			break;
		}
		cout << "? " << hi << endl;
		cin >> a;
		if(a=='N'){
			hi--;
			while(low+1<hi){
				LL m=(low+hi)/2;
				cout << "? " << m*10 << endl;
				cin >> a;
				if(a=='Y'){
					hi=m;
				}
				else{
					low=m;
				}
			}
			cout << "! " << hi << endl;
			break;
		}
		low*=10;
		hi*=10;
	}

	return 0;
}

