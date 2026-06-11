#include<iostream>
#include<string>
#define LL long long
int N;
int sum;
int main() {
	LL N;
	std::cin >> N;
	LL lb = 1;
	LL ub = N;
	while (ub - lb > 1) {
		LL mid = (lb + ub) / 2;
		if ((mid + 1LL)*mid / 2LL>=N) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}
	for (int i = 1; i <= ub; i++) {
		if (i == (ub + 1) * ub / 2 - N)continue;
		std::cout << i << std::endl;
	}
	return 0;
}