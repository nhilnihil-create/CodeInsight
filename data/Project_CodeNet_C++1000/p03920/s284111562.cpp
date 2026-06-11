#include<iostream>
#include<vector>
#include<map>

#define TGT 10000000

using namespace std;

int main(void) {
	vector<int> triangle(5000);
	int sum = 0, N, i;

	cin >> N;

	for (i = 0; sum < N; i++) {
		sum += i;
	}

	for (i--; N > 0; i--) {
		if (i <= N) {
			N -= i;
			cout << i << endl;
		}
	}


	//system("pause");

	return 0;
}