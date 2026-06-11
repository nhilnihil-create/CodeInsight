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
	int a, b;
	cin >> a >> b;
	int c[a];
	for (int i = 0 ; i < a ; i++) cin >> c[i];
	sort(c,c + a);
	int x = 0;
	for (int i = a - 1 ; i > a - 1 - b ; i--) {
		x += c[i];
	}
	cout << x;
}