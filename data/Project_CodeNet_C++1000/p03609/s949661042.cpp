#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	int x,t;
	cin >> x >> t;
	x -= t;
	if(x >0) {
		cout << x << endl;
	}else {
		cout << 0 << endl;
	}
	return 0;
}
