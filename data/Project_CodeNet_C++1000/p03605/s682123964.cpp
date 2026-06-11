#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string N;
	cin >> N;

	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '9') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
}
