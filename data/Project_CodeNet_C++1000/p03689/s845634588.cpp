#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

int a[500][500];
const int aa = 1000000000;

void solve()
{
    int H, W, h, w;
    scanf("%d%d%d%d", &H, &W, &h, &w);

    if (h == 1 && w == 1) {
        printf("No\n"); return;
    }
    else if (H % h ==0 && W % w == 0) {
        printf("No\n"); return;
    }
    else if (W % w == 0) {
        printf("Yes\n");
        int i, j;
        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
                if (i%h == 0 && j%w == w - 1) {
                    printf("%d", aa-1);
                }
                else if (i%h == h - 1 && j%w == w - 1) {
                    printf("%d", -aa);
                }
                else {
                    printf("0");
                }
                if (j < W - 1) printf(" ");
                else printf("\n");
            }
        }
    }
    else {
        printf("Yes\n");
        int i, j;
        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++) {
                if (i%h == h-1 && j%w == 0) {
                    printf("%d", aa-1);
                }
                else if (i%h == h - 1 && j%w == w - 1) {
                    printf("%d", -aa);
                }
                else {
                    printf("0");
                }
                if (j < W - 1) printf(" ");
                else printf("\n");
            }
        }
    }


    return;
}


int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}
