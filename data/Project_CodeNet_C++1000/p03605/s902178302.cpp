#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	
	if ((N - 9) % 10 == 0) {
		cout << "Yes" << endl;
	}

	else if (90 <= N) {
		cout << "Yes" << endl;
	}

	else {
		cout << "No" << endl;
	}
}



