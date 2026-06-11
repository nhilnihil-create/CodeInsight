#include <cstring>
#include <cstdio>
#include <algorithm>
const int MAXN = 100010;
using namespace std;

int N, A[MAXN];

inline bool greaterInt(int x, int y) { return x > y; }
inline bool out(int x, int y) { return x > N - 1 || y >= A[x]; }
int main() {
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N, greaterInt);

	int x = 0, y = 0;
	while(!out(x, y)) x++, y++;
	x--, y--;

	int lx = 0, ly = 0;
	while(!out(x + lx, y)) lx++;
	while(!out(x, y + ly)) ly++;

	bool lose = ((lx & 1) == 1) && ((ly & 1) == 1);
	printf(lose ? "Second" : "First");
	return 0;
}
