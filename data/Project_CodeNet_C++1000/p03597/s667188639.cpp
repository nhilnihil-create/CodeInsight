#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_bichrome_cells(void) {
	int n, a;
	cin >> n >> a;

	n *= n;

	cout << (n - a) << endl;
}

int main()
{
    a_bichrome_cells();
    return 0;
}