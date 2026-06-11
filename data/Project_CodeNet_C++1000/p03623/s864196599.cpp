#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);

	int n, m,x; cin >>x>> n >> m;
	if (abs(n - x) <= abs(m - x))cout << "A" << endl;
	else if (abs(n - x) > abs(m - x))cout << "B" << endl;
	return 0;
}

