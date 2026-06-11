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
	int x, a, b;
	cin >> x >> a >> b;
	if (abs(x - a) > abs(x - b)) cout << 'B';
	else cout << 'A'; 
}