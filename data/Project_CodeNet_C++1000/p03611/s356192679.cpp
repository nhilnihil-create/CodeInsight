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
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    int n, b;
    cin >> n;
    int a[100000] = {};
    for (int i = 0 ; i < n ; i++) {
    	cin >> b;
    	if (b > 0) a[b - 1]++;
    	a[b]++;
    	a[b + 1]++;
	}
	int c = 0;
	for (int i = 0 ; i < 100000 ; i++) c = max(c, a[i]);
	cout << c;
}