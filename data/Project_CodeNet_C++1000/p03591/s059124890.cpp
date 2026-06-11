#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;

	if (S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I' && S.length() >= 4) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}


