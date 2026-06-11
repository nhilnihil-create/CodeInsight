#include <iostream>
using namespace std;
char colors[1001][1001];
#define rep(i,n) for(int i=0;i<n;++i)

int main()
{
    int h; cin >> h;
    int w; cin >> w;
    int d; cin >> d;

    rep (i, 1001) {
        char color1 = (((i / d) & 1LL) ? 'R' : 'Y');
        char color2 = (((i / d) & 1LL) ? 'G' : 'B');
        rep (j, 1001) {
            colors[i][j] = (((j / d) & 1LL) ? color1 : color2);
        }
    }

    int sx = 500;
    int sy = 0;

    rep (i, h) {
        int x = sx;
        int y = sy;
        rep (j, w) {
            cout << colors[x++][y++];
        }
        cout << endl;
        sx--;
        sy++;
    }

    return 0;
}
