#include <bits/stdc++.h>
using namespace std;

bool func(int a, int b, int sum)
{
	for (int i = 0; a * i <= sum; i++)
	{
		if ((sum - a * i) % b == 0)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	/*
100A+100B+C+D<=F
(A+B)*E>=C+D

*/
	int A, B, C, D, E, F;
	int water, sugar;
	double dense;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
	double max_dense = 0;
	double max_dense_water = 100 * A;
	double max_dense_sugar = 0;

	for (water = 0; water <= F; water += 100)
	{
		dense = 0;
		if (!func(A * 100, B * 100, water))
		{
			continue;
		}
		for (sugar = min(F - water, water / 100 * E); sugar >= 0; sugar--)
		{
			if (func(C, D, sugar))
			{
				dense = (double)sugar / (double)(sugar + water);
				break;
			}
		}
		if (dense > max_dense)
		{
			max_dense = dense;
			max_dense_water = water;
			max_dense_sugar = sugar;
		}
		// if (max_dense == (double)E / (double)(100 + E))
		// {
		// 	break;
		// }
	}

	cout << max_dense_water + max_dense_sugar << " " << max_dense_sugar;
	return 0;
}