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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	long long k;
	cin >> k;
	cout << "50" << endl;
	vector<long long> hoge;
	REP(i, 50) {
		hoge.push_back(49);
	}
	for (int i = 0;i < hoge.size();++i) {
		hoge[i] += k / 50;
	}
	for (int i = 0;i < k % 50;++i) {
		for (int q = 0;q < hoge.size();++q) {
			hoge[q]--;
		}
		hoge[i] += 51;
	}
	REP(i, 50) {
		cout << hoge[i] << " ";
	}
	cout << endl;
	return 0;
}