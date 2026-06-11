#include <cstdlib>
#include <iostream>
int main(void) {
    const int mod = 1000000007;
    int n;
	while (std::cin >> n) {
		long long ans = 1;
		int fail = 0, stack = 0, *arr, *cnt;
		arr = new int[n];
		cnt = new int[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
			++cnt[(fail + 1) / 2];
			if (i == 0) {
				arr[0] = 1;
			}
			else {
				if (arr[i] >= arr[i - 1] + 2) {
					arr[i] = arr[i - 1] + 2;
				}
				if (arr[i - 1] + 1 == arr[i]) {
					++fail;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			stack += cnt[i];
			ans *= stack--;
			ans %= mod;
		}
		std::cout << ans << std::endl;
		delete[] arr;
		delete[] cnt;
	}
	return EXIT_SUCCESS;
}