#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
	int N;
	std::cin >> N;

	int ans = 1;
	int cnt_max = 0;
	for(int i = 1; i <= N; i++)
	{
		int num = i;
		int cnt = 0;
//		printf("%d:", num / 2);
		while(((num % 2) == 0) && (num != 0) && (num != 1))
		{
			num /= 2;
			cnt++;
//			printf("+");
		}
//		printf("[%d}%d\n", i, cnt);
		if(cnt > cnt_max)
		{
			ans = i;
			cnt_max = cnt;
		}
		cnt = 0;
	}

	std::cout << ans << std::endl;

    return 0;
}
