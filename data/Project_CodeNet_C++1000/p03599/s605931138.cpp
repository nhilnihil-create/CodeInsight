#include <cstdio>

bool w[6666] = { true }, s[6666] = { true };

int main(void)
{
	double max = -1.0;
	int a, b, c, d, e, f, i, j, ansa = 0, ansb = 0;

	scanf("%d %d %d %d %d %d" ,&a, &b, &c, &d, &e, &f);
	a *= 100, b *= 100;

	for (i = 0; i <= f; i++)
	{
		if (w[i])
		{
			w[i + a] = true;
			w[i + b] = true;
		}
		if (s[i])
		{
			s[i + c] = true;
			s[i + d] = true;
		}
	}

	for (i = 100; i <= f; i += 100)
	{
		if (!w[i])
			continue;

		for (j = 0; j <= f - i; j++)
		{
			if (!s[j])
				continue;

			if (j * 100 <= e * i)
			{
				double t = (double)j / (i + j);

				if (max < t)
				{
					max = t;
					ansa = i + j;
					ansb = j;
				}
			}
			else
				break;
		}
	}

	printf("%d %d" ,ansa, ansb);
	return 0;
}