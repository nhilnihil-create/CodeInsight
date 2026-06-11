#include <iostream>
#include <map>
#include <vector>

using namespace std;

int Task4Core();

int main()
{
	cout << Task4Core();

	return 0;
}
int Task4Core()
{
	int N = 0;

	cin >> N;

	map<int, int> num; // 差分、個数
	
	for (int i = 0; i < N; ++i) {
		int n = 0;
		cin >> n;
		++num[n];

		bool isError = true;
		if (N % 2 != 0) { // 奇数
			if (n % 2 != 0) {
				return 0;
			}
			else if (n > N - 1) {
				return 0;
			}
		}
		else {
			if (n % 2 == 0) {
				return 0;
			}
			else if (n > N - 1) {
				return 0;
			}
		}
	}

	//　並び方は人数によって決まる。

	int numPower = N / 2;

	int product = 1;
	int numerator = 1000000000 + 7;
	for (int i = 0; i < numPower; ++i) {
		if ((N % 2) != 0) {// 奇数の場合
			if (i == 0) {
				if (num[i] != 1) {// 左右比較が0 の場合
					return 0;
				}
			}
			else {
				if (num[2 * i] != 2) {
					return 0;
				}
			}
		}
		else {
			if (num[2 * i + 1] != 2) {
				return 0;
			}
		}
		product = (product * 2) % numerator;
	}

	return product;
}