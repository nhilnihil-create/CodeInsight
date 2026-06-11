#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	char s[100010];
	scanf("%s", s);
	int N = strlen(s);

	int all_g = 0;
	for (int i = 0; i < N; i++)
		all_g += s[i] == 'g' ? 0 : -1;

	printf("%d\n", all_g + N / 2);

	return 0;
}
