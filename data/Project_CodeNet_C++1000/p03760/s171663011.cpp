#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_ango(void) {
	string o, e;
	cin >> o >> e;
	int total_size = o.size() + e.size();
	bool odd_size = (total_size & 0x1) == 0x1 ? true : false;
	total_size = (total_size + 1) >> 1;
	for (int i = 0; i < total_size; i++) {
		cout << o[i];
		if (i != (total_size - 1)) cout << e[i];
		else {
			if (!odd_size) cout<<e[i];
		}
	}
	cout << endl;
}

int main()
{
	b_ango();
    return 0;
}