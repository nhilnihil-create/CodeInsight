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
    int n;
    cin >> n;
    set <int> s;
    int a;
    for (int i = 0 ; i < n ; i++) {
    	cin >> a;
    	if (s.count(a) == 0) s.insert(a);
    	else s.erase(a);
	}
	cout << s.size();
}