#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int R, C, d;
	cin >> R >> C >> d;
	string clr = "RGBY";
	for (int i = 0; i<R; ++i, puts(""))
		for (int j = 0; j < C; ++j) {
			int a = (i - j + 500) / d % 2;
			int b = (i + j + 500) / d % 2;
			printf("%c", clr[a * 2 + b]);
		}
	return 0;
}