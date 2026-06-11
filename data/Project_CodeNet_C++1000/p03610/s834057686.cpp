#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if ((i + 1) % 2 == 1) {
			cout << S[i];
		}
	}
	cout << endl;
	
}
