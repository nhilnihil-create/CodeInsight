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
	int x,a,b;
	cin >> x >> a >>b;
	if (a>=b) cout << "delicious" << endl;
	if ((a + x) >= b && a <b) cout << "safe" << endl;
	if ((a +x) <b) cout << "dangerous" << endl;
	return 0;
}
