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
	ll n,m;
	cin >> n >> m;
	if (n*2<=m) {
		cout << n+(m-n*2)/4;
	} else if (n*2>m) {
		cout << m/2;
	}
}