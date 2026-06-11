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
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	int MIN = 0, MAX = 0;
	//bool malti = false;
	vector<int> color(9,0);
	for (int i = 0; i < N; i++) {
		if (a[i] < 400)color[0]++;
		else if (a[i] < 800) color[1]++;
		else if (a[i] < 1200) color[2]++;
		else if (a[i] < 1600) color[3]++;
		else if (a[i] < 2000) color[4]++;
		else if (a[i] < 2400) color[5]++;
		else if (a[i] < 2800) color[6]++;
		else if (a[i] < 3200) color[7]++;
		else color[8]++;
	}
	for (int i = 0; i < 8; i++) {
		if (color[i] > 0) {
			MIN++;
			MAX++;
		}
	}
	MAX += color[8];
	if (MIN != 0) {
		cout << MIN << " " << MAX << endl;
	}
	else {
		cout << 1 << " " << MAX << endl;
	}
}
