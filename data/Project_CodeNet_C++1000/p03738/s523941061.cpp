#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	string A, B;
	cin >> A >> B;//A>BでGREATER 小さくてLESS 等しくてEQUAL
	if (A.size() > B.size()) cout << "GREATER" << endl;
	else if (A.size() < B.size()) cout << "LESS" << endl;
	else {
		if (A > B) cout << "GREATER" << endl;
		else if (A < B) cout << "LESS" << endl;
		else cout << "EQUAL" << endl;
	}
}