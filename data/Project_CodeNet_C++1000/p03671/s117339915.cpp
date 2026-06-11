#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();

	int x, y, z;
	cin >> x >> y >> z;
	if ((x + y) < (x + z) && (x + y) < (y + z))
		cout << (x + y) << endl;
	else if ((x + z) < (z + y) && (x + z) < (y + x))
		cout << (x + z) << endl;
	else if ((z + y) < (x + z) && (z + y) < (y + x))
		cout << (z + y) << endl;
	else
		cout << x + y << endl;
}