#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
const int MaxN = 500;
using namespace std;
char s[10], res[MaxN + 5][MaxN + 5];
bool vis[4 * MaxN + 5][5];
int n, m, d;
string len = "RYGB";
int main() 
{
	while(~scanf("%d%d%d", &n, &m, &d)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = ((i + j) % (2 * d) + 2 * d) % (2 * d) / d;
				int y = ((i - j) % (2 * d) + 2 * d) % (2 * d) / d;
				putchar(len[2 * x + y]);
			}
			printf("\n");
		}
	}
}