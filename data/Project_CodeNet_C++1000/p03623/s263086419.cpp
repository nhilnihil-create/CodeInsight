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
	int mi = abs (x-a);
	int mi2 = abs(x-b);
	if (mi < mi2) cout << 'A' << endl;
	else cout << 'B' << endl;
	return 0;
}
