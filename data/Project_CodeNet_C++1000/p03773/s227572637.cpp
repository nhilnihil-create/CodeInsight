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

	int time = A + B;

	if (time >= 24) {
		cout << time - 24 << endl;
	}
	else {
		cout << time << endl;
	}


}
