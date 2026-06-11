#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int a = A % 3;
	int b = B % 3;
	int ab = (A + B) % 3;

	if (a == 0 || b == 0 || ab == 0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	
}
