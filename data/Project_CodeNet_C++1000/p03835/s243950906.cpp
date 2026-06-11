#include <iostream>
using namespace std;

int main() {
	int K, S;
	cin >> K >> S;

	int res = 0;
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= K; ++k)
				if (i + j + k == S) ++res;

	cout << res << endl;
}