#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int total = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		total += a;
	}

	if (total % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}




