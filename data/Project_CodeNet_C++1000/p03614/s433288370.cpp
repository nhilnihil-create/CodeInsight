#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ul;

const int iinf = 1 << 29;
const long long linf = 1l << 61;

int N;
int p[100800];

int main(int argc, char* argv[])
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &p[i]);

	int ans = 0;
	int j = 0;
	for(int i = 0; i < N; i++)
	{
		if(p[i] == i + 1)
		{
			j++;
		}
		else
		{
			ans += j / 2 + j % 2;
			j = 0;
		}
	}
	ans += j / 2 + j % 2;
	printf("%d\n", ans);

	return 0;
}
