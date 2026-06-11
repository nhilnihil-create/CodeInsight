#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2010;
int n, m, d, p1, p2,cnt;
int ans[N][N];
char mp[4] = {'R', 'Y', 'G', 'B'};
int c1,c2;
int main(){
    scanf("%d%d%d", &n, &m, &d);
    for (int i = -1010; i <= 1010; i += d) {
		c1 ^= 1;
        for (int j = -1010; j <= 1010; j += d) {
			c2 ^= 1;
			int c = c1 << 1 | c2;
            for (int x = 0; x < d; x++)
                for (int y = 0; y < d; y++) {
                    if (i + x + j + y < 0 || i + x - j - y < 0) continue;
                    //cout <<((i + x + j + y) >> 1)<<"  "<<((i + x - j - y) >> 1)<<endl;
                    ans[(i + x + j + y) >> 1][(i + x - j - y) >> 1] = c;
                }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            putchar(mp[ans[i][j]]);
        putchar('\n');
    }
    return 0;
}
