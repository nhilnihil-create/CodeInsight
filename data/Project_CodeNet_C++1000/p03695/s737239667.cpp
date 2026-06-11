#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++) cin >> a[i];
	int b[9] = {};
	for (int i = 0 ; i < n ; i++) {
		if (a[i] >= 1 && a[i] <= 399) b[0]++;
		else if (a[i] >= 400 && a[i] <= 799) b[1]++;
		else if (a[i] >= 800 && a[i] <= 1199) b[2]++;
		else if (a[i] >= 1200 && a[i] <= 1599) b[3]++;
		else if (a[i] >= 1600 && a[i] <= 1999) b[4]++;
		else if (a[i] >= 2000 && a[i] <= 2399) b[5]++;
		else if (a[i] >= 2400 && a[i] <= 2799) b[6]++;
		else if (a[i] >= 2800 && a[i] <= 3199) b[7]++;
		else b[8]++;
	}
	int c = 0;
	for (int i = 0 ; i < 8 ; i++) {
		if (b[i] >= 1) c++;
		
	}
	cout << max(1, c) << ' ' << c + b[8];
}