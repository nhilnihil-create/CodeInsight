#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
	int N, K;
	std::cin >> N >> K;
	std::vector<int> x(N);
	rep(i, N)	std::cin >> x[i];
	
	int ans = 0;
	rep(i, N)
	{
		ans += 2 * (std::min(abs(x[i] - 0), abs(x[i] - K)));
	//	printf("[%d]%d\n", i, ans);
	}

	std::cout << ans << std::endl;

    return 0;
}
