#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int areaAB = a * b;
	int areaCD = c * d;

	if (areaAB >= areaCD) {
		cout << areaAB << endl;
	}
	else {
		cout << areaCD << endl;
	}

	return 0;
}