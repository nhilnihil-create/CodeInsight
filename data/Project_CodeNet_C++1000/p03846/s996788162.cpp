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
	}

	//　並び方は人数によって決まる。

	int numPower = N / 2;

	// int product = 1;
	int divisor = 1000000000 + 7;

	// map は key によりソートされているはず。

	const bool isOdd = (N % 2 == 0) ? false: true;
	int numP = (isOdd) ? 0 : 1;
	int product = 1;
	auto elem = num.begin();

	int limit = N / 2;
	if (isOdd) {
		++limit;
	}
	for (int i = 0; i < limit; ++i, numP += 2) {
		// numP += 2;

		if (isOdd && i == 0) {
			if (num[0] != 1) {
				return 0;
			}

		}
		else if (num[numP] != 2) {
			return 0;
		}
		if (isOdd == false || i != 0) {
			product = (product * 2) % divisor;
		}
	}
	
	return product;
}