#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
void a_shiritori(void) {
	string a, b, c;
	cin >> a >> b >> c;

	if ((a[a.size() - 1] == b[0])&&(b[b.size()-1]==c[0])) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


int main()
{
    a_shiritori();
    return 0;
}