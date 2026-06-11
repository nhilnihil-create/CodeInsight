#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))

#define MOD 1000000007
#define INF 1000000000

int H, W, d;
int ans[510][510];
char ret[510][510];
int main()
{
    ZERO(ans);
    ZERO(ret);
    cin >> H >> W >> d;

    if(d % 2 != 0) {
        REP(i, H) {
            char tile1, tile2;
            if(i % 2 == 0) {
                tile1 = 'R';
                tile2 = 'G';
            } else {
                tile1 = 'G';
                tile2 = 'R';
            }
            REP(j, W) {
                if(j % 2 == 0) { printf("%c", tile1); }
                else { printf("%c", tile2); }
            }
            printf("\n");
        }
    } else {
#if 1
        REP(i, H) {
            char up, down, left, right;
            for(int j = 0; j < W; j += d) {
                if(((i + j) / d) % 2 == 0) {
                    up = 'R';
                    down = 'G';
                    left = 'Y';
                    right = 'B';
                } else {
                    up = 'G';
                    down = 'R';
                    left = 'B';
                    right = 'Y';
                }
                int up_n = d - (i % d) * 2;
                if(i % d >= d / 2) { up_n = 0; }
                int down_n = ((i % d) - d / 2) * 2;
                if(i % d <= d / 2) { down_n = 0; }
                int width_n;
                if(i % d <= d / 2) {
                    width_n = i % d;
                } else {
                    width_n = d - (i % d);
                }
                int ind = j;
                for(int k = 0; k < width_n && ind < W; k++, ind++) { printf("%c", left); }
                for(int k = 0; k < up_n && ind < W; k++, ind++) { printf("%c", up); }
                for(int k = 0; k < down_n && ind < W; k++, ind++) { printf("%c",down); }
                for(int k = 0; k < width_n && ind < W; k++, ind++) { printf("%c", right); }
            }
            printf("\n");
        }
#else
        for(int i = 0; i < H; i += d) {
            for(int j = 0; j < W; j += d) {
                int h = 1;
                int sign = 1;
                for(int k = j; k < j + d && k < W; ++k) {
                    int diff = k - j;
                    if(diff >= d / 2 && sign > 0) {
                        sign = -1;
                        h += (1 * sign);
                    }
                    ans[i][k] = h;
                    if(i + h < H) { ans[i + h][k] = d - (h * 2 - 1); }
                    h += (1 * sign);
                }
            }
        }
        char tile1 = 'R', tile2 = 'Y', tile3 = 'B';
        for(int i = 0; i < H; i += d) {
            if(tile1 == 'G') { tile1 = 'R'; }
            else { tile1 = 'G'; }
            if(tile2 == 'Y') {
                tile2 = 'B';
                tile3 = 'Y';
            }
            else {
                tile2 = 'Y';
                tile3 = 'B';
            }
            char tmp1 = tile1;
            char tmp2 = tile2;
            char tmp3 = tile3;
            for(int j = 0; j < W; ++j) {
                if(j % d == 0) {
                    if(tmp1 == 'G') { tmp1 = 'R'; }
                    else { tmp1 = 'G'; }
                    if(tmp2 == 'Y') {
                        tmp2 = 'B';
                        tmp3 = 'Y';
                    }
                    else {
                        tmp2 = 'Y';
                        tmp3 = 'B';
                    }
                }
                for(int k = 0; k < ans[i][j]; ++k) {
                    if(i + k < H) { ret[i + k][j] = tmp1; }
                    if(i - k >= 0) { ret[i - k][j] = tmp1; }
                }
                if(i + ans[i][j] < H) {
                    for(int k = 0; k < ans[i+ans[i][j]][j]; ++k) {
                        if(i + 1 + k < H) {
                            if(j % d < d / 2) { ret[i + ans[i][j] + k][j] = tmp2; }
                            else { ret[i + ans[i][j] + k][j] = tmp3; }
                        }
                    }
                }
            }
        }
        //REP(i, H) {
        //    REP(j, W) {
        //        printf("%d ", ans[i][j]);
        //    }
        //    printf("\n");
        //}
        //printf("---\n");
        REP(i, H) {
            REP(j, W) {
                printf("%c", ret[i][j]);
            }
            printf("\n");
        }
#endif
    }
    return 0;
}
