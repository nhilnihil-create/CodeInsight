#include <cstdio>
static const int MAXN = 502;

int h, w, d;
int s[MAXN][MAXN];
const char *colour = "GYRB";

inline void paint(int colour, int r, int c)
{
    for (int i = 0; i < d / 2; ++i)
        for (int j = -i; j <= i; ++j)
            if (r + i >= 0 && r + i < h && c + j >= 0 && c + j < w)
                s[r + i][c + j] = colour;
    for (int i = (d - 1) / 2; i >= 0; --i)
        for (int j = -i; j <= i; ++j)
            if (r + d - 1 - i >= 0 && r + d - 1 - i < h && c + j >= 0 && c + j < w)
                s[r + d - 1 - i][c + j] = colour;
}

int main()
{
    scanf("%d%d%d", &h, &w, &d);

    int r, c, p;
    if (d == 1) {
        for (r = 0; r < h; ++r)
            for (c = 0; c < w; ++c)
                paint((r & 1) << 1 | (c & 1), r, c);
    } else {
        for (r = 0, c = -1000, p = 0; r < 1000; r += d / 2, c += (d + 1) / 2, p ^= 1) {
            int rr = r, cc = c, q = 0;
            for (; cc < 1000; rr -= (d + 1) / 2, cc += d / 2, q ^= 1)
                paint((p << 1) | q, rr, cc);
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            putchar(colour[s[i][j]]);//, putchar(' ');
        putchar('\n');
    }

    return 0;
}
