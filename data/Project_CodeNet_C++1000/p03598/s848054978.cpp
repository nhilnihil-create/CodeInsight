#include <iostream>
#include<cmath>
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
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k;
	int y = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		if (k - x < x) y += k - x;
		else y += x;  
	}
	cout << y * 2;
}
