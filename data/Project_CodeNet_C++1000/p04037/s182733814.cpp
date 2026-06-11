#include <cstdio>
#include <algorithm>

const int MAXN = 1e5 + 5;

int a [MAXN];

int main ()
{
	int n, p;
	scanf ("%d", &n);
	
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a [i]);
		
	std::sort (a + 1, a + n + 1, std::greater <int> ());
			
	for (int i = 1; i <= n; i ++)
		if (i + 1 > a [i + 1])
		{
			int j;
			
			for (j = 0; a [i + j + 1] == i; j ++);
			
			if ((a [i] - i) % 2 || j % 2)
				puts ("First");
			
			else
				puts ("Second");
				
			return 0;
		}
}