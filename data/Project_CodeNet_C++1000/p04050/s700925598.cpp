#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> inputs;
	REP(i, m) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	reverse(inputs.begin(), inputs.end());
	if (m == 1) {
		if (n == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
		}
		else {
			cout << inputs[0] << endl;
			cout << 2 << endl;
			cout << n - 1 << " " << 1 << endl;
		}
	}
	else{
		int ok = 0;
		REP(i, inputs.size()) {
			ok += inputs[i] % 2;
		}
		if (ok > 2) {
			cout << "Impossible" << endl;
		}
		else {
			int gogo[2] = { -1,-1 };
			for(int i = inputs.size()-1;i >= 0;--i){
				if (inputs[i] % 2 == 1) {
					if (gogo[0] == -1) {
						gogo[0] = i;
					}
					else {
						gogo[1] = i;
					}
				}
			}
			if (gogo[0] != -1) {
				swap(inputs[inputs.size()-1], inputs[gogo[0]]);
				if (gogo[1] != -1) {
					swap(inputs[0], inputs[gogo[1]]);
				}
			}
			REP(i, inputs.size()) {
				cout << inputs[i] << " ";
			}
			cout << endl;
			inputs[0]--;
			inputs[inputs.size() - 1]++;
			if (inputs[0] == 0) {
				inputs.erase(inputs.begin());
			}
			cout << inputs.size() << endl;
			REP(i, inputs.size()) {
				cout << inputs[i] << " ";
			}
			cout << endl;
		}
	}
}