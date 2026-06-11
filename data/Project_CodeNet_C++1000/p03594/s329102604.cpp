#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const int inf = (int)1.05e9;

const char* colors = "RGBY";

int main()
{
	int h, w, d;
	vector<vector<char>> ans;

	scanf("%d%d%d", &h, &w, &d);
	ans.resize(h);
	for(auto& x : ans)
		x.resize(w);

	int s = d;
	if(d % 2 == 1)
		s = 1;

	for(int x = 0; x < w; ++x) {
		for(int y = 0; y < h; ++y) {

			int p = x - y + s * 100000;
			int q = x + y + s * 100000;

			int pg = (p / s) & 1;
			int qg = (q / s) & 1;
			int c = pg * 2 + qg * 1;

			ans[y][x] = c;
		}
	}

	for(int y = 0; y < h; ++y) {
		for(int x = 0; x < w; ++x) {
			int c = ans[y][x];
			printf("%c", colors[c]);
			//printf("%d ", c);
		}
		printf("\n");
	}


	return 0;
}

/* waffle */
