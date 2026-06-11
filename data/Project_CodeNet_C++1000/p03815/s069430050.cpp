#define _USE_NATH_DEFINES
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<iomanip>
#include<tuple>
#include<stack>
#include<random>
#include<chrono>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

const int INF = 1e9;
const double MINF = -1e9;


int main() {
	
	long long x;
	cin >> x;
	long long cnt = 0;

	cnt = x/11 * 2;
	long long tmp = x % 11;
	if (tmp) {
		if (tmp > 6) cnt += 2;
		else cnt += 1;
	}
	

	cout << cnt << endl;
	return 0;
}