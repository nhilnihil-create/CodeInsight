#include <iostream>
#include <string>

using namespace std;

bool IsSiritori(string inputs[], int length) {
	bool result = true;
	for (int i = 1; i < length; i++) {
		if (inputs[i].front() != inputs[i - 1].back()) {
			result = false;
			break;
		}
	}
	return result;
}

int main()
{
	string inputs[3]{};
	cin >> inputs[0] >> inputs[1] >> inputs[2];
	cout << (IsSiritori(inputs, 3) ? "YES" : "NO") << endl;
	return 0;
}
