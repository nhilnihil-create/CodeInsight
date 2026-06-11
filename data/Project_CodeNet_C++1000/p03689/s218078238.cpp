/*
如果H是h的倍数且W是w的倍数，那么整个矩阵可以看成是被(H / h) * (W / w)个h * w的子矩形覆盖。若每个子矩形和为负数，整个矩形和也一定为负数，故无解
下面给出这么一种构造方法：考虑H是h的倍数和W是w的倍数两个条件最多一个成立时，取一维上不是倍数的。以H不是h的倍数为例
将行从0开始编号。若第p mod h = 0，那么第p行全填V * (h - 1) - 1，否则第p行全填-V。那么有： 
(1)对于每个h * w的子矩阵，恰好跨越1个编号mod h = 0的行和h - 1个编号mod h > 0的行，元素和 = ((V * (h - 1) - 1) * 1 - V * (h - 1)) * w = -w
(2)对于整个矩阵，考虑把所有行按照ceil(p / H)分段，每一个完整的段和都是-W。对于不完整的段，贡献显然是个关于V的一次函数kV + b，其中k > 0
那么取一个很大的V（满足填的数不超过上限）即可，手算一下发现满足条件 
*/

#include <cstdio>
#include <algorithm>

using namespace std;
const int Max_HW(505);

int H, W, h, w, Ans[Max_HW][Max_HW], V;
bool Rev;

int main()
{
	scanf("%d%d%d%d", &H, &W, &h, &w);
	if (H % h == 0 && W % w == 0)
	{
		puts("No");
		return 0;
	}
	if (H % h == 0)
		swap(H, W), swap(h, w), Rev = true;
	V = 1000000;
	for (int i = 0;i <= H - 1;++i)
		if (i % h == 0)
			for (int j = 0;j <= W - 1;++j)
				Ans[i][j] = V * (h - 1) - 1;
		else
			for (int j = 0;j <= W - 1;++j)
				Ans[i][j] = -V;
	puts("Yes");
	if (Rev)
	{
		swap(H, W);
		for (int i = 0;i <= H - 1;++i)
		{
			for (int j = 0;j <= W - 1;++j)
				printf("%d ", Ans[j][i]);
			printf("\n");
		}
	}
	else
		for (int i = 0;i <= H - 1;++i)
		{
			for (int j = 0;j <= W - 1;++j)
				printf("%d ", Ans[i][j]);
			printf("\n");
		}
	return 0;
}