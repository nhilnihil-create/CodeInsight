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
	int x , a , b;
    cin >> x >> a >> b;
    if (a >= b) cout << "delicious";
    else if (a + x >= b) cout << "safe";
    else cout << "dangerous";
}